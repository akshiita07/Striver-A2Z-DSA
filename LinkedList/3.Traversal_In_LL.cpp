#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data=data1;
        next=nullptr;       //by default give nullptr to all
    }
};

Node* convertArrToLL(int arr[],int n){
    Node* head=new Node(arr[0]);
    Node* mover=head;

    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }

    return head;    //returns location of head
}

// TIME: O(n)
void traverseLL(Node* head){
    // to print this ll
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
    
    Node* head=convertArrToLL(arr,n);
    traverseLL(head);

    return 0;
}