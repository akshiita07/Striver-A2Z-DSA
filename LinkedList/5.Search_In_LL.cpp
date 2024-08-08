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

// TIME: WORST CASE: O(n)       BEST CASE: O(1)->1st element found
int searchLL(Node* head,int element){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==element){
            // found
            return 1;
        }
        temp=temp->next;
    }
    // not found
    return 0;
}

int main()
{
    int arr[]={2,4,6,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    Node* head=convertArrToLL(arr,n);
    int elem1=11;
    int elem2=6;
    cout<<elem1<<" : "<<searchLL(head,elem1)<<endl;
    cout<<elem2<<" : "<<searchLL(head,elem2)<<endl;

    return 0;
}