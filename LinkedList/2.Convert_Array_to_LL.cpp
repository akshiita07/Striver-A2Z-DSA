#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};

// return pointer to head
Node* convertArrToLL(int arr[],int n){
    Node* head=new Node(arr[0],nullptr);
    Node* mover=head;

    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i],nullptr);
        mover->next=temp;
        mover=temp;     //or mover=mover->next
    }
    return head;
}

int main()
{
    int arr[]={2,4,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);

    Node* result=convertArrToLL(arr,n);
    cout<<"The head data is: "<<result->data<<endl;

    return 0;
}