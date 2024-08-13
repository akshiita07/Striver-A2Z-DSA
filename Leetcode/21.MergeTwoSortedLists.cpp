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

// BRUTE FORCE:

// TIME: O(n1)->list1 traversal + O(n2)->list2 traversal + O(log(n1+n2))->sort + O(n1+n2)->convert vector to LL == O(n1+n2+log(n)+n)
// SPACE: O(n)->to maintain vector of merged LL

// take all elements of LL in array->sort array->convert arr to ll
Node* convertVectorToLL(vector<int> arr){
    int n=arr.size();
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* newNode=new Node(arr[i]);
        mover->next=newNode;
        mover=newNode;
    }
    return head;
}
Node *brute_force(Node *list1, Node *list2){
    vector<int> merged;
    Node* temp1=list1;
    while(temp1!=nullptr){
        merged.push_back(temp1->data);
        temp1=temp1->next;
    }
    Node* temp2=list2;
    while(temp2!=nullptr){
        merged.push_back(temp2->data);
        temp2=temp2->next;
    }

    // sort this merged array
    sort(merged.begin(),merged.end());
    // convert it into LL:
    Node* mergedLL=convertVectorToLL(merged);
    return mergedLL;
}

// OPTIMAL::
// TIME: O(n1)->traverse list1 + O(n2)->traverse list2 == O(n1+n2)
// SPACE: O(1)
Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *ptr1 = list1;
    Node *ptr2 = list2;
    Node *mergedListHead = new Node(-1); // dummy node with data= -1
    Node *temp = mergedListHead;

    // loop until 1 of the LL traversal finishes
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->data <= ptr2->data)
        {
            Node *mergedList = new Node(ptr1->data);
            ptr1 = ptr1->next;
            temp->next = mergedList;
            temp = mergedList;
        }
        else
        {
            Node *mergedList = new Node(ptr2->data);
            ptr2 = ptr2->next;
            temp->next = mergedList;
            temp = mergedList;
        }
    }

    // remaining nodes
    while (ptr1 != nullptr)
    {
        Node *mergedList = new Node(ptr1->data);
        temp->next = mergedList;
        temp = mergedList;
        temp->next=nullptr;     //last node so point to null
        ptr1 = ptr1->next;
    }
    while (ptr2 != nullptr)
    {
        Node *mergedList = new Node(ptr2->data);
        temp->next = mergedList;
        temp = mergedList;
        temp->next=nullptr;     //last node so point to null
        ptr2 = ptr2->next;
    }

    Node *newHead = mergedListHead->next;
    return newHead;
}

int main()
{
    int arr1[] = {1, 2, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node *node1 = convertArrToLL(arr1, n1);
    cout << "\nTraversing LL1: ";
    traverse(node1);

    int arr2[] = {1, 3, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *node2 = convertArrToLL(arr2, n2);
    cout << "\nTraversing LL2: ";
    traverse(node2);

    cout << "\nOn merging both LL, the sorted list is: ";
    // Node *mergedNode = brute_force(node1, node2);
    Node *mergedNode = mergeTwoLists(node1, node2);
    traverse(mergedNode);

    return 0;
}