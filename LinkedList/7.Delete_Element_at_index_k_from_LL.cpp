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

int countNodesOfLL(Node *head)
{
    int count=0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *deleteNode(Node *head, int index)
{

    int length = countNodesOfLL(head);
    // if LL provided is empty:
    if (index > length)
    {
        cout << "Sorry no such index exists !" << endl;
        return NULL;
    }
    if(head==NULL){
        cout << "Sorry no elements r present in LL!" << endl;
        return NULL;
    }

    if (index == 1)
    {
        // delete head of LL
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    else if (index == length)
    {
        // delete tail of LL
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }
    else
    {
        // delete element in between
        Node *temp = head;
        Node *prev = NULL;  //to rem prev element
        // reach upto that element
        int count=1;        //initially at head count=1
        // if index from 0 then take count=-1
        while(temp!=nullptr)
        {
            count++;
            if(count==index){
                // change pointers
                prev->next=prev->next->next;
                delete temp;
                break;
            }
            prev=temp;  //move prev to temp
            temp = temp->next;  //move temp
        }

        return head;
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = convertArrToLL(arr, n);

    cout << "The linked list is: " << endl;
    traverseLL(head);

    int index;
    cout << "\nEnter index to delete from LL: ";
    cin >> index;

    Node *newHead = deleteNode(head, index);

    cout << "The linked list after "<<index<<" is deleted: " << endl;
    traverseLL(newHead);

    return 0;
}