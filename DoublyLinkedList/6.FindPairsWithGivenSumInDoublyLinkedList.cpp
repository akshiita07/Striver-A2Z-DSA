#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1)
    {
        data = data1;
        next = nullptr; // initialise to null if not provided
        prev = nullptr; // initialise to null if not provided
    }

    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node *convertArrToDoubleLL(int arr[], int n)
{
    Node *head = new Node(arr[0]); // both next & prev=nullptr
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
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

//  sorted doubly linked list of size 'n'
// Find out all the pairs(2 elem) in the doubly linked list with sum equal to 'k'.

// TIME: O(n)->outer loop using temp * O(n)->inner loop using ptr= O(n^2)
// SPACE: O(1)
vector<pair<int, int>> brute_force(Node *head, int k)
{
    vector<pair<int, int>> ans;
    if (head == NULL || head->next == nullptr)
    {
        ans.push_back(make_pair(0, 0));
        return ans;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        int sum = 0;
        Node *ptr = temp->next;
        while (ptr != nullptr)
        {
            sum = temp->data + ptr->data;
            if (sum == k)
            {
                // add this pair
                ans.push_back(make_pair(temp->data, ptr->data));
            }
            if (sum > k)
            {
                // no more can be found as LL is sorted!
                break;
            }
            else
            {
                // check for next value of ptr
                ptr = ptr->next;
            }
        }
        temp = temp->next;
    }
    return ans;
}

// OPIMAL-using property that LL is sorted!!
// TIME: O(n)->to move right to tail + O(n)->for sum= O(2n)
// SPACE: O(1)
vector<pair<int, int>> findPairs(Node *head, int k)
{
    vector<pair<int, int>> ans;
    if (head == NULL || head->next == nullptr)
    {
        ans.push_back(make_pair(0, 0));
        return ans;
    }

    // left pointer starts from head
    Node *left = head;

    // right pointer goes to tail of LL
    Node *right = head;
    while (right->next != nullptr)
    {
        right = right->next;
    }

    // continue until left crosses right
    while (left->data<right->data)
    {
        int sum = left->data + right->data;

        if (sum == k)
        {
            ans.push_back(make_pair(left->data, right->data));
            left = left->next;
            right = right->prev;
        }
        else if (sum > k)
        {
            // lower down right
            right = right->prev;
        }
        else
        {
            // move left
            left = left->next;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = convertArrToDoubleLL(arr, n);
    traverse(head);

    int k;
    cout << "\nEnter element SUM= ";
    cin >> k;

    // vector<pair<int, int>> ans = brute_force(head, k);
    vector<pair<int, int>> ans = findPairs(head, k);

    cout << "\nThe pairs in doubly LL that sum upto " << k << " are: ";
    for (auto it : ans)
    {
        cout << "(" << it.first << "," << it.second << ")    ";
    }
    // Output: (1, 4) and (2, 3)

    return 0;
}