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

Node *insertBeforeHead(Node *head, int element)
{
    // if empty list is given
    if (head == NULL)
    {
        Node *temp = new Node(element);
        head = temp;
        return head;
    }
    Node *temp = new Node(element);
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

Node *insertBeforeTail(Node *head, int element)
{
    // if empty list is given
    if (head == NULL)
    {
        Node *temp = new Node(element);
        head = temp;
        return head;
    }
    Node *temp = head;
    Node *mover = NULL;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    // temp is at tail & mover is one before
    mover = temp->prev;
    Node *newNode = new Node(element);
    mover->next = newNode;
    newNode->prev = mover;
    newNode->next = temp;
    temp->prev = newNode;
    return head;
}

Node *insertBeforeKth(Node *head, int element, int index)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        if (count == index)
        {
            Node *backward = temp->prev;
            Node *forward = temp->next;
            if (backward == NULL && forward == NULL)
            {
                // only 1 element exists
                // before head
                Node* newNode=new Node(element);
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
                return head;
            }
            else if (backward == NULL)
            {
                // before head
                Node* newNode=new Node(element);
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
                return head;
            }
            else if (forward == NULL)
            {
                // before tail 
                Node* newNode=new Node(element);
                backward->next=newNode;
                newNode->prev=backward;
                newNode->next=temp;
                temp->prev=newNode;
                return head;
            }
            else
            {
                Node* newNode=new Node(element);
                backward->next=newNode;
                newNode->prev=backward;
                newNode->next=temp;
                temp->prev=newNode;                
                return head;
            }
        }
        temp = temp->next;
    }
    return NULL;
}

void insertBeforeNode(Node *toDeleteNode, int element)
{
    // NOT PROVIDED WITH HEAD AS WELL
    Node *backward = toDeleteNode->prev;
    Node *forward = toDeleteNode->next;

    if (backward == NULL && forward == NULL)
    {
        Node* newNode=new Node(element);
        newNode->next=toDeleteNode;
        toDeleteNode->prev=newNode;
    }
    else if (backward == NULL)
    {
        // head
        Node* newNode=new Node(element);
        newNode->next=toDeleteNode;
        toDeleteNode->prev=newNode;
    }
    else if (forward == NULL)
    {
        // tail
        Node* newNode=new Node(element);
        newNode->next=toDeleteNode;
        toDeleteNode->prev=newNode;
    }
    else
    {
        // in between
        Node* newNode=new Node(element);
        backward->next=newNode;
        newNode->prev=backward;
        newNode->next=toDeleteNode;
        toDeleteNode->prev=newNode;
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = convertArrToDoubleLL(arr, n);

    cout << "The Doubly LL is: " << endl;
    traverse(head);

    int element;
    cout << "\nEnter value of element to be inserted: ";
    cin >> element;

    // Node *newLL = insertBeforeHead(head, element);
    // cout << "The Doubly LL after " << element << " is inserted before head is: " << endl;
    // traverse(newLL);

    // Node* newLL=insertBeforeTail(head,element);
    //  cout<<"The Doubly LL after "<<element<<" is inserted before TAIL is: "<<endl;
    // traverse(newLL);

    // int index;
    // cout << "Enter index before which element is to be inserted in doubly LL: " << endl;
    // cin >> index;
    // Node *newLL = insertBeforeKth(head,element, index);
    // cout<<"The Doubly LL after "<<element<<" is inserted before index= "<<index<<" is: "<<endl;
    // traverse(newLL);

    Node *newNode = head->next->next;
    insertBeforeNode(newNode,element);
     cout<<"The Doubly LL after "<<element<<" is inserted before this given node is: "<<endl;
    traverse(head);

    return 0;
}