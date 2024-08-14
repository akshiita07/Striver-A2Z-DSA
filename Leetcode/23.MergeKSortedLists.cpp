#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

Node *convertArrToLL(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// BRUTE FORCE: ADD ALL ELENENTS IN SEPARATE ARRAY THEN SORT IT N CONVERT TO LL
Node *convertVectorToLL(vector<int> &list)
{
    Node *head = new Node(list[0]);
    Node *ptr = head;
    for (int i = 1; i < list.size(); i++)
    {
        Node *newNode = new Node(list[i]);
        ptr->next = newNode;
        ptr = newNode;
    }
    return head;
}
// TIME: O(k)->traverse k lists * O(n)->each traversal of LL * O(log2(k*n))-->to sort elements + O(k*n)->to convert vector to LL== O(n*k+log2(k*n)+k*n)== O(2*n*k + log2(n*k))
// SPACE: O(k*n)->stores elements in vector + O(k*n)->to convert vec back to LL
Node *brute_force(vector<Node *> &lists)
{
    vector<int> mergedList;
    int n = lists.size();
    for (int i = 0; i < n; i++)
    {
        Node *temp = lists[i];
        while (temp != nullptr)
        {
            mergedList.push_back(temp->data);
            temp = temp->next;
        }
    }
    // sort this LL
    sort(mergedList.begin(), mergedList.end());
    // convert it back to LL
    Node *mergedLL = convertVectorToLL(mergedList);
    return mergedLL;
}

// USING MERGE
// TIME: O(k * O(n1+n2)->to merge 2 lists)-> merging k times
// O(n*k*(k+1)/2) == O(n^3)-> v high!!
// SPACE: O(1)
Node *merge2LL(Node *list1, Node *list2)
{
    Node *dummy = new Node(-1);

    Node *ptr = dummy;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data <= list2->data)
        {
            ptr->next = list1;
            ptr = list1;
            list1 = list1->next;
        }
        else
        {
            ptr->next = list2;
            ptr = list2;
            list2 = list2->next;
        }
    }
    // remaining
    if (list1)
    {
        ptr->next = list1;
    }
    if (list2)
    {
        ptr->next = list2;
    }

    Node *head = dummy->next;
    delete dummy; // free up space
    return head;
}

Node *mergeKLists(vector<Node *> &lists)
{
    // traverse to end of LL & merge
    int n = lists.size();
    if (n == 0)
    {
        // check:
        return NULL;
    }
    Node *head = lists[0];
    for (int i = 1; i < n; i++)
    {
        // we have alredy kept 0th one in head so start from i=1
        Node *temp = lists[i];
        head = merge2LL(head, temp); // returns new head
    }
    return head;
}

// OPTIMAL APPROACH USING MIN HEAP-> RETURNS MIN VALUE
// PRIORITY QUEUE IS USED TO IMPLEMENT MIN HEAP
// TIME: O(k*(log2(k)))->to push heads into for loop + O(n*k*log2(k))->while loop until pq is empty == O(n^2)
// prioriy queue operations take O(logn)
// SPACE: O(k)->adding heads in pq
Node *optimalApproach(vector<Node *> &lists)
{
    int n = lists.size();
    if (n == 0)
    {
        // check:
        return NULL;
    }
    // using priority queue
    priority_queue<pair<int, Node *>,vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;//BY DEF IT IS MAX HEAP SO WE HAVE TO ADD GREATER HERE
    // initially pq consists of all head nodes
    for (int i = 0; i < n; i++)
    {
        // push heads only
        pq.push({lists[i]->data, lists[i]});
    }

    Node *dummy = new Node(-1);
    Node *ptr = dummy;

    // loop thru pq until empty
    while (!pq.empty())
    {
        auto p = pq.top(); // gives MIN element
        pq.pop(); // delete it from pq

        // now get next from pq
        if (p.second->next != nullptr)
        {
            pq.push({p.second->next->data, p.second->next});
        }
        ptr->next = p.second;
        ptr=ptr->next;
    }
    Node* head=dummy->next;
    return head;
}

int main()
{
    vector<Node *> arrayOfLists;
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    Node *node1 = convertArrToLL(arr1, n1);
    Node *node2 = convertArrToLL(arr2, n2);
    Node *node3 = convertArrToLL(arr3, n3);

    // push these LL inside vector
    arrayOfLists.push_back(node1);
    arrayOfLists.push_back(node2);
    arrayOfLists.push_back(node3);

    cout << "\nTraversing vector of LL: ";
    for (auto it : arrayOfLists)
    {
        cout << "[ ";
        traverse(it);
        cout << "] ";
    }

    cout << "\nThe merged linked list is: ";
    // Node *mergedLL = brute_force(arrayOfLists);
    // Node *mergedLL = mergeKLists(arrayOfLists);
    Node *mergedLL = optimalApproach(arrayOfLists);
    traverse(mergedLL);
    // Output: [1,1,2,3,4,4,5,6]

    return 0;
}