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

Node* revereLL(Node* head){
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr){
        Node* forward=temp->next;
        temp->next=prev;
        prev=temp;
        temp=forward;
    }
    return prev;
}
int *getIntersectionNode(Node *headA, Node *headB)
{
    Node* reversedA=revereLL(headA);
    Node* ptrA=reversedA;
    Node* reversedB=revereLL(headB);
    Node* ptrB=reversedB;

    int intersectionNode=NULL;

    while(ptrA!=nullptr && ptrB!=nullptr){
        // check until where same
        if(ptrA->data==ptrB->data){
            // continue iterating
            ptrA=ptrA->next;
            ptrB=ptrB->next;
        }else{
            // the point where it changes is the node
        }
    }
    return intersectionNode;

}

int main()
{
    int arr1[] = {4, 1, 8, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node *node1 = convertArrToLL(arr1, n1);
    cout << "\nTraversing LL1: ";
    traverse(node1);

    int arr2[] = {5, 6, 1, 8, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *node2 = convertArrToLL(arr2, n2);
    cout << "\nTraversing LL2: ";
    traverse(node2);

    cout << "\nIntersected at node whose value is: " << getIntersectionNode(node1, node2);

    return 0;
}