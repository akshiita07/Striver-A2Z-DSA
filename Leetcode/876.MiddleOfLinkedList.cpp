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
int countNodes(Node *head)
{
    // TIME:O(n)
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// TIME:O(n)+O(n/2)->2 pass
int brute_force(Node *head)
{
    int len = countNodes(head); // TIME:O(n)

    Node *temp = head;
    int n = len / 2;
    // move pointer n times
    for (int i = 1; i <= n; i++)
    {
        // TIME:O(n/2)
        temp = temp->next;
    }
    return temp->data;
    return -1;
}

// Tortoise & Hare Algorithm
// TIME:O(n/2)->1 pass
int middleNode(Node *head)
{
    // fast moves till end by moving 2 steps & slow moves till middle by moving only 1 step at a time
    Node* slow=head;
    Node* fast=head;
    // stop when fast reaches the last node-> odd count
    // stop when fast reaches NULL-> even count
    while(fast!=nullptr && fast->next!=nullptr){
        // if any of these cnd is true then do not execute this code:
        slow=slow->next;        //moves by 1 step
        fast=fast->next->next;      //moves by 2 steps
    }
    // return slow;
    return slow->data;
}

int main()
{
    // for odd count: return mid
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node *node1 = convertArrToLL(arr1, n1);
    cout << "\nTraversing LL1: ";
    traverse(node1);
    cout << "\nBRUTE FORCE: The middle element of LL1 is: " << brute_force(node1); // 3
    cout << "\nOPTIMAL--> The middle element of LL1 is: " << middleNode(node1); // 3

    cout << endl;

    // for even count: two middle nodes: return the second middle node.
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *node2 = convertArrToLL(arr2, n2);
    cout << "\nTraversing LL2: ";
    traverse(node2);
    cout << "\nBRUTE FORCE: The middle element of LL2 is: " << brute_force(node2); // 4
    cout << "\nOPTIMAL--> The middle element of LL2 is: " << middleNode(node2); // 4

    return 0;
}