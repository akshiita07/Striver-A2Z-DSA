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

Node *deleteNode(Node *head, int value)
{
    // if LL provided is empty:
    if(head==NULL){
        cout << "Sorry no elements r present in LL!" << endl;
        return NULL;
    }

    Node* temp=head;
    Node* prev=NULL;
    while(temp!=nullptr){
        if(temp->data==value){
            // element found
            if(prev==NULL){
                // first element to be deleted
                head=head->next;
                temp->next=nullptr;
                delete temp;
                return head;
            }else{
                prev->next=prev->next->next;
                delete temp;
                return head;
            }
        }
        prev=temp;
        temp=temp->next;
    }
    cout<<"No such element found in LL with value as "<<value<<endl;
    return 0;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = convertArrToLL(arr, n);

    cout << "The linked list is: " << endl;
    traverseLL(head);

    int value;
    cout << "\nEnter value to delete from LL: ";
    cin >> value;

    Node *newHead = deleteNode(head, value);

    cout << "The linked list after "<<value<<" element is deleted: " << endl;
    traverseLL(newHead);

    return 0;
}