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

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *insertAtK(Node *head, int element, int index)
{
    // for empty ll
    if (head == NULL)
    {
        Node *newNode = new Node(element);
        head = newNode;
        return head;
    }
    if (index == 1)
    {
        // at head
        Node *newNode = new Node(element);
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            // countmust point to one index before to add new element
            if (count == (index - 1))
            {
                Node *newNode = new Node(element);
                newNode->next = temp->next;
                temp->next = newNode;
                return head;
            }
            temp = temp->next;
        }
        // not a valid index
        cout << "Index entered is not valid";
        return NULL;
    }
}

Node *insertAfterElement(Node *head, int element, int value)
{
    if (head->data == value)
    {
        // insert at head
        Node *newNode = new Node(element);
        newNode->next=head;
        head=newNode;
        return head;
    }
    // find node where this value is present
    Node *temp = head;
    // & keep a prev pointer
    Node *prev = NULL;

    while (temp != nullptr)
    {
        if ((temp->data) == value)
        {
            // found so insert
            Node *newNode = new Node(element);
            newNode->next = temp;
            prev->next = newNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Such value not found in LL";
    return NULL;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *newNode = convertArrToLL(arr, n);
    cout << "The linked list is: " << endl;
    traverse(newNode);

    int element;
    cout << "\nEnter element to be inserted in LL: ";
    cin >> element;

    // int index;
    // cout << "\nEnter index at which " << element << " is to be inserted in LL: ";
    // cin >> index;
    // Node *KInsert = insertAtK(newNode, element, index);
    // cout << "\nInsertion at K:";
    // traverse(KInsert);

    int value;
    cout << "\nEnter value BEFORE which " << element << " is to be inserted in LL: ";
    cin >> value;
    Node *ElementInsert = insertAfterElement(newNode, element, value);
    cout << "\nInsertion at tail:";
    traverse(ElementInsert);

    return 0;
}
