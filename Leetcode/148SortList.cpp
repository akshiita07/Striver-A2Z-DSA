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

Node *brute_force(Node *head)
{
    vector<int> list;
    Node* temp=head;
    while(temp!=nullptr){
        list.push_back(temp->data);
        temp=temp->next;
    }
    sort(list.begin(),list.end());

    // add these elem back in ll
    temp=head;
    int i=0;
    while(temp!=nullptr){
        temp->data=list[i];
        i++;
        temp=temp->next;
    }
    return head;    
}

int main()
{
    int arr[] = {1, 0, 2, 1, 0, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

    Node* sortedNode=brute_force(node);
    cout<<"\nAfter sorting LL is: ";
    traverse(sortedNode);

    return 0;
}