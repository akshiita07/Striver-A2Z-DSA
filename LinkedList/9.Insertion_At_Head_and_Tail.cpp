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

void traverse(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* insertAtHead(Node* head,int element){
    Node* newNode=new Node(element);    //data as element
    newNode->next=head;
    head=newNode;
    return head;
}

Node* insertAtTail(Node* head,int element){
    if(head==NULL){
        // create 1 single node
        Node* newNode=new Node(element);
        head=newNode;
        return head;
    }
    
    Node* temp=head;
    while(temp->next!=nullptr){
        // now at last element
        temp=temp->next;
    }
    Node* newNode=new Node(element);
    temp->next=newNode;
    return head;
}

int main()
{
    int arr[]={2,4,6,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    Node* newNode=convertArrToLL(arr,n);
    cout << "The linked list is: " << endl;
    traverse(newNode);

    int element;
    cout<<"\nEnter element to be inserted in LL: ";
    cin>>element;

    // Node* headInsert=insertAtHead(newNode,element);
    // cout<<"\nInsertion at head:";
    // traverse(headInsert);

    Node* tailInsert=insertAtTail(newNode,element);
    cout<<"\nInsertion at tail:";
    traverse(tailInsert);

    return 0;
}
