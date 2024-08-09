#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1)
    {
        data = data1;
        next = nullptr; // initialise to null if not provided
        prev = nullptr; // initialise to null if not provided
    }

    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node *convertArrToDoubleLL(int arr[], int n)
{
    Node *head = new Node(arr[0]); // both next & prev=nullptr
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
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

Node *deleteHead(Node *head)
{
    // if empty list is given or only 1 element in list then:
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;    // move head to next element
    head->prev = nullptr; // ie the next elem must not point backwards to it
    temp->next = nullptr; // it must also not point anywhere
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    // if empty list is given or only 1 element in list then:
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    Node *mover = NULL;
    while (temp->next != nullptr)
    {
        mover = temp; // 1 place behind
        temp = temp->next;
    }
    mover->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

Node *kthElement(Node *head, int index)
{
    // if empty list is given or only 1 element in list then:
    if (head == NULL || head->next == NULL)
    {
        cout << "\nEither LL is empty or cts only 1 element.";
        return NULL;
    }

    if (index == 1)
    {
        // delete head
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    else
    {
        // some other index

        Node *temp = head;
        Node *mover = NULL;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            if (count == index)
            {
                // delete it
                mover = temp->prev;
                temp->prev = nullptr;

                // for tail element no next exists
                if (temp->next == nullptr)
                {
                    // at tail element
                    mover->next = nullptr;
                    return head;
                }
                // else:
                mover->next = temp->next;
                temp->next->prev = mover;
                temp->next = nullptr;
                return head;
            }
            temp = temp->next;
        }
        cout << "No such index found in LL!" << endl;
        return NULL;
    }
}

// better code::
// Node *deleteNode(Node *head, int x)
// {
//     // Your code here
//     int count = 0;
//     Node *temp = head;
//     while (temp != nullptr)
//     {
//         count++;
//         if (count == x)
//         {
//             Node *backward = temp->prev;
//             Node *forward = temp->next;
//             if (backward == NULL && forward == NULL)
//             {
//                 delete temp;
//                 return NULL;
//             }
//             else if (backward == NULL)
//             {
//                 // head
//                 head = forward;
//                 forward->prev = nullptr;
//                 temp->next = nullptr;
//                 delete temp;
//                 return head;
//             }
//             else if (forward == NULL)
//             {
//                 // tail
//                 backward->next = nullptr;
//                 temp->prev = nullptr;
//                 delete temp;
//                 return head;
//             }
//             else
//             {
//                 backward->next = forward;
//                 forward->prev = backward;
//                 temp->next = nullptr;
//                 temp->prev = nullptr;
//                 return head;
//             }
//         }
//         temp = temp->next;
//     }
//     return NULL;
// }

void deleteANode(Node *toDeleteNode)
{
    // NOT PROVIDED WITH HEAD AS WELL
    Node *backward = toDeleteNode->prev;
    Node *forward = toDeleteNode->next;

    if (backward == NULL && forward == NULL)
    {
        // only single node exists
        delete toDeleteNode;
    }else if(backward==NULL){
        // head
        forward->prev=nullptr;
        toDeleteNode->next=nullptr;
    }else if(forward==NULL){
        // tail
        backward->next=nullptr;
        toDeleteNode->prev=nullptr;
    }else{
        // in between
        backward->next=forward;
        forward->prev=backward;
        toDeleteNode->prev=nullptr;
        toDeleteNode->next=nullptr;
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = convertArrToDoubleLL(arr, n);

    cout << "The Doubly LL is: " << endl;
    traverse(head);

    // Node* newLL=deleteHead(head);
    // cout<<"The Doubly LL after head is deleted: "<<endl;
    // traverse(newLL);

    // Node* newLL=deleteTail(head);
    // cout<<"The Doubly LL after TAIL is deleted: "<<endl;
    // traverse(newLL);

    // int index;
    // cout << "Enter index at which element is to be deletd from doubly LL: " << endl;
    // cin >> index;
    // Node *newLL = kthElement(head, index);
    // cout << "The Doubly LL after index= " << index << " is deleted: " << endl;
    // traverse(newLL);

    Node *newNode = head->next->next;
    deleteANode(newNode);
    cout << "The Doubly LL after new node is deleted: " << endl;
    traverse(head);

    return 0;
}