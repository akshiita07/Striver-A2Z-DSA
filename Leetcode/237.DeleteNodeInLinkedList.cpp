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

void traverseLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteNode(Node *node)
{
    int value = node->data; // elem to be deleted
    cout<<"We are deleting node with value= "<<value<<endl; 
    // convert this node with the next node data
    // if((node->next)==nullptr){
    //     // tail node
    //     // prev
    // }
    node->data=node->next->data;
    node->next=node->next->next;
    node=node->next;
    // delete node;
    return node;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = convertArrToLL(arr, n);

    cout << "The linked list is: " << endl;
    traverseLL(head);

    Node* toDelete=head->next->next;

    Node *newHead = deleteNode(toDelete);

    cout << "The linked list after node deleted: " << endl;
    traverseLL(newHead);

    return 0;
}