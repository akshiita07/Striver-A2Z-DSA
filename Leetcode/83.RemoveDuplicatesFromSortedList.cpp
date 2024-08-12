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
    Node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        Node* newNode=temp->next;
        while(newNode!=nullptr && temp->data==newNode->data){
            // continue
            Node* duplicateElement=newNode;
            newNode=newNode->next;
            delete duplicateElement;
        }
        temp->next=newNode;
        temp=temp->next;
    }
    return head;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

    cout << "\nAfter removal of duplicates LL is: ";
    Node *newLL = deleteDuplicates(node);
    traverse(newLL);

    return 0;
}