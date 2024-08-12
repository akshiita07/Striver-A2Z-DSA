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

Node *brute_force(Node *head)
{
    if (head == NULL || head->next == nullptr)
    {
        return head;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->next != nullptr && (temp->data == temp->next->data))
        {
            Node *forward = temp->next;
            if (temp == head)
            {
                // to delete head element
                head = forward;
            }
            Node *backward = temp->prev;
            if (backward)
            {
                backward->next = forward;
            }
            if (forward)
            {

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

// TIME: O(n)->outer loop with skipping duplicates* O(n)->only to duplicates = O(n) NOT N^2!!! 😮
// SPACE: O(1)
Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while (temp!=nullptr && temp->next!=nullptr)
    {
        Node *newNode = temp->next;
        while (newNode != nullptr && temp->data == newNode->data)
        {
            Node* duplicateNode=newNode;
            // keep moving newNode until we reach a unique node
            newNode = newNode->next;
            delete duplicateNode ;    
        }
        // change links:
        temp->next = newNode;
        if (newNode)
        {
            newNode->prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = convertArrToDoubleLL(arr, n);
    traverse(head);

    cout << "\nAfter removing duplicates, LL is: ";

    // Node *newLL = brute_force(head);
    Node* newLL=removeDuplicates(head);

    traverse(newLL);

    return 0;
}