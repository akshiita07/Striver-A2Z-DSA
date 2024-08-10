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

int findLen(Node *head)
{
    // TIME: O(n)
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
// TOTAL TIME:O(n+n)=O(2n)
Node *removeNthFromEnd(Node *head, int n)
{
    // if no element or only single element
    if (head == nullptr || head->next == nullptr)
    {
        // single elm would be deleted
        return nullptr;
    }
    int len = findLen(head);
    int key = len - n;
    // delete node after key:
    if (key == 0) // or even if n==len ie delete first element
    {
        // delete head node
        Node *ptr = head;
        head = head->next;
        ptr->next = nullptr;
        delete ptr;
        return head;
    }
    else
    // TIME: O(LENGTH-N)
    {
        // delete in between node
        int c = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            c++;
            if (c == key)
            {
                Node *elem = temp->next;
                // delete the node after it
                temp->next = elem->next;
                delete elem;
                return head;
            }
            temp = temp->next;
        }
    }
    return NULL;
}

// OPTIMISE:
// take fast pointer & move it given n steps
// take slow pointer & move both fast & slow simultanoulsy 1 by 1
// until fast reaches last node then stop
// slow will point at prev node

// TOTAL TIME:O(n) ie single iteration
Node *optimal(Node *head, int n)
{
    // if no element or only single element
    if (head == nullptr || head->next == nullptr)
    {
        // single elm would be deleted
        return nullptr;
    }

    Node *fast = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if(fast==nullptr){
        // ie it moved upto length of LL
        // ie delete head node
        Node *ptr = head;
        head = head->next;
        ptr->next = nullptr;
        delete ptr;
        return head;
    }

    Node *slow = head;
    // until fast reaches LAST node
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // now slow points to prev pos
    Node *elementToDelete = slow->next;
    // delete the node after it
    slow->next = elementToDelete->next;
    delete elementToDelete;
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

    int key = 2;
    // Node *newNode = removeNthFromEnd(node, key);
    Node *newNode = optimal(node, key);
    cout << "\nTraversing LL after removing " << key << " node from end of LL: ";
    traverse(newNode);

    return 0;
}