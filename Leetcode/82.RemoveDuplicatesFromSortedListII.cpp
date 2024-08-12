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

Node *deleteDuplicates(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }

    Node *dummy = new Node(0, head); // new dummy node with value=0 that points to head
    Node *temp = head;
    Node *prev = dummy;

    while (temp != nullptr)
    {
        if (temp->next != nullptr && temp->data == temp->next->data)
        {
            while (temp->data == temp->next->data)
            {
                // continue
                temp = temp->next;
            }
            prev->next = temp->next;
        }
        else
        {
            // No duplicates, move the prev pointer
            prev = prev->next;
        }
        temp = temp->next;
    }
    head=dummy->next;
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

    cout << "\nAfter removal of ALL duplicates LL is: ";
    Node *newLL = deleteDuplicates(node);
    traverse(newLL);

    return 0;
}