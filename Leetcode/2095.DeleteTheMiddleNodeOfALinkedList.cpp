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

// USING OPTIMIZED TORTOISE & HARE APPROACH:
Node *deleteElement(Node *head, Node *nodeToDelete)
{
    int c = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != nullptr)
    {
        if (temp == nodeToDelete)
        {
            if (c == 0)
            {
                // delete 1st index
                head = head->next;
                temp->next = nullptr;
                delete temp;
                return head;
            }
            prev->next = temp->next;
            delete temp;
            return head;
        }
        c++;
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *deleteMiddle(Node *head)
{// if single element in LL or empty LL
    if (head == NULL || head->next == nullptr)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    Node *newLL = NULL;
    // for odd length: fast->next=nullptr
    // for even length: fast-=nullptr
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    newLL = deleteElement(head, slow); // middle element
    return newLL;
}

// reach slow 1 step before middle node so skip 1 step of slow
// TIME: O(n/2)
// SPACE: O(1)
Node *optimalApproach(Node *head)
{// if single element in LL or empty LL
    if (head == NULL || head->next == nullptr)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    fast = fast->next->next;
    // for odd length: fast->next=nullptr
    // for even length: fast-=nullptr
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
     // middle element is slow->next;
    Node* middleEle=slow->next;
    slow->next=middleEle->next;
    delete middleEle;
    return head;
}

int main()
{
    // odd length list
    int arr1[] = {1, 3, 4, 7, 1, 2, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node *node1 = convertArrToLL(arr1, n1);
    cout << "\nTraversing LL1: ";
    traverse(node1);
    // deleteMiddle(node1);
    optimalApproach(node1);
    cout << "\nAfter deleting middle element of LL1: ";
    traverse(node1);

    // even length list
    int arr2[] = {1, 2, 3, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *node2 = convertArrToLL(arr2, n2);
    cout << "\nTraversing LL2: ";
    traverse(node2);
    // deleteMiddle(node2);
    optimalApproach(node2);
    cout << "\nAfter deleting middle element of LL2: ";
    traverse(node2);

    return 0;
}