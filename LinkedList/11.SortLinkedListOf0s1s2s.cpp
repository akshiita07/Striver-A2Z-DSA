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

// TOTAL TIME: O(n+n+nlogn)
Node *brute_force(Node *head)
{
    vector<int> list;
    Node* temp=head;
    // TIME:O(n)
    while(temp!=nullptr){
        list.push_back(temp->data);
        temp=temp->next;
    }
    // TIME:O(nlogn)
    sort(list.begin(),list.end());

    // add these elem back in ll
    temp=head;
    int i=0;
    // TIME:O(n)
    while(temp!=nullptr){
        temp->data=list[i];
        i++;
        temp=temp->next;
    }
    return head;    
}

// TOTAL TIME: O(n+n)=O(2n)
Node *usingCounter(Node *head)
{
    Node* temp=head;
    int count0=0;
    int count1=0;
    int count2=0;
    // TIME:O(n)
    while(temp!=nullptr){
        if(temp->data==0){
            count0++;
        }else if(temp->data==1){
            count1++;
        }else if(temp->data==2){
            count2++;
        }
        temp=temp->next;
    }

    // add these elem back in ll
    temp=head;
    // TIME:O(n)
    while(temp!=nullptr){
        if(count0>0){
            temp->data=0;
            count0--;
        }else if(count1>0){
            temp->data=1;
            count1--;
        }else if(count2>0){
            temp->data=2;
            count2--;
        }
        temp=temp->next;
    }
    return head;    
}

// optimal::
// TIME: O(n)
// SPACE: O(1)
Node *sortList(Node *head)
{
    // if empty/1element
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    // 3 dummy nodes indicating start of 0,1,2
    Node* list0=new Node(-1);
    Node* zeroPointer=list0;
    Node* list1=new Node(-1);
    Node* onePointer=list1;
    Node* list2=new Node(-1);
    Node* twoPointer=list2;

    Node* temp=head;
    // TIME: O(n)
    while(temp!=nullptr){
        if(temp->data==0){
            zeroPointer->next=temp;
            zeroPointer=temp;
        }else if(temp->data==1){
            onePointer->next=temp;
            onePointer=temp;
        }else if(temp->data==2){
            twoPointer->next=temp;
            twoPointer=temp;
        }
        temp=temp->next;
    }
    // now last 2 element must point to null
    twoPointer->next=nullptr;

    // 0 ke baad connect 1 ka head
    if(list1->next!=nullptr){
        // make sure if no 1s then atatch to 2s else it wil be nullptr
        zeroPointer->next=list1->next;
    }else{
        zeroPointer->next=list2->next;
    }
    // 1 ke baad connect 2 ka head
    onePointer->next=list2->next;
    // update new head
    head=list0->next;

    // free up space by deleting dummy nodes
    delete list0,list1,list2;

    return head;    
}

int main()
{
    int arr[] = {1, 0, 2, 1, 0, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

// 3 approaches:
    // Node* sortedNode=brute_force(node);
    // Node* sortedNode=usingCounter(node);
    Node* sortedNode=sortList(node);

    cout<<"\nAfter sorting LL is: ";
    traverse(sortedNode);

    return 0;
}