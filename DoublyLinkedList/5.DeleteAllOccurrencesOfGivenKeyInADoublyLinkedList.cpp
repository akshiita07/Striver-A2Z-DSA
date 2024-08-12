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

// TIME: O(n)->traversal n:no of nodes
// SPACE: O(1)-> no extra space used
Node *deleteAllOccurrences(Node *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == k)
        {
            Node *backward = temp->prev;
            Node *forward = temp->next;
            // check if head is also to be deleted:
            if (temp == head)
            {
                // delete head
                head = forward;
            }
            if (backward)
            {
                backward->next = forward;
            }
            if (forward)
            {
                // if next exists-> case for tail element
                forward->prev = backward;
            }
            delete temp;
            temp = forward;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    int arr[] = {10, 4, 10, 3, 5, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = convertArrToDoubleLL(arr, n);
    cout << "\nThe LL initially is: ";
    traverse(head);

    int key;
    cout << "\nEnter element which has to be deleted= ";
    cin >> key;

    Node *newLL = deleteAllOccurrences(head, key);
    cout << "\nThe new LL is: ";
    traverse(newLL);

    return 0;
}