#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1){
        data=data1;
        next=nullptr;       //initialise to null if not provided
        prev=nullptr;       //initialise to null if not provided
    }

    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
};

Node* convertArrToDoubleLL(int arr[],int n){
    Node* head=new Node(arr[0]);    //both next & prev=nullptr
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        temp->prev=mover;
        mover=temp;
    }
    return head;
}

void traverse(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    int arr[]={2,4,6,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* head=convertArrToDoubleLL(arr,n);
    traverse(head);

    return 0;
}