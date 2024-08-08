#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data=data1;
        next=nullptr;
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
    return head;
}

void traverseLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* deleteHead(Node* head){

    // if LL provided is empty:
    if(head==NULL){
        cout<<"Sorry i have recieved an empty LL!"<<endl;
        return head;
    }

    Node* temp=head;      //start from head
    head=head->next;    //move head to next position
    temp->next==nullptr;
    delete temp;        //to delete temp ie first node from memory also
    return head;
}

Node* deleteTail(Node* head){

    // if LL provided is empty:
    // if LL has only 1 element then delete that itself
    if(head==NULL || head->next==nullptr){
        cout<<"Sorry i have recieved an empty LL or there is a single element only!"<<endl;
        return NULL;
    }


    Node* temp=head;      //start from head
    while((temp->next->next)!=nullptr){
        // reach last index
        temp=temp->next;
    }
    delete temp->next;  //free up tail element
    temp->next=nullptr;

    return head;
}

int main()
{
    int arr[]={2,4,6,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    Node* head=convertArrToLL(arr,n);

    cout<<"The linked list is: "<<endl;
    traverseLL(head);

    // Node* newHead=deleteHead(head);
    // cout<<"The linked list after head is deleted: "<<endl;

    Node* newHead=deleteTail(head);
    cout<<"The linked list after tail is deleted: "<<endl;

    traverseLL(newHead);

    return 0;
}