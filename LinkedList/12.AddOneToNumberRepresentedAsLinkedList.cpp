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

Node *reverseLL(Node *head)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        Node *forward = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forward;
    }
    return prev;
}

// TIME:O(n+n+n)=O(3n)
// SPACE: O(1)
Node *addOne(Node *head)
{
    // reverse this given LL
    Node *newHead = reverseLL(head); // TIME:O(n)
    Node *temp = newHead;
    Node *prev = nullptr; // for last element tracker
    int carry = 0;
    while (temp != nullptr)
    {
        // TIME:O(n)
        int sum = carry;
        // for first node only add 1
        if (temp == newHead)
        {
            sum += temp->data + 1;
        }
        else
        {
            // else add only carry & value
            sum += temp->data;
        }
        temp->data = sum % 10;
        carry = sum / 10;
        if (carry == 0)
        {
            break;
            // completed execution
        }
        prev = temp;
        temp = temp->next;
    }
    // if still a carry is remaining then a new node has to be added at end with value=carry
    if (carry == 1)
    {
        Node *newNode = new Node(carry);
        // prev points to last element
        prev->next = newNode;
        newNode->next = nullptr;
    }

    // again reverse this LL to get ans
    Node *newAns = reverseLL(newHead); // TIME:O(n)
    return newAns;
}

// OPTIMAL APPROACH -> WITHOUT REVERSING
// USE RECURSION-> BACKTRACKING
// TIME:O(n)
// SPACE:O(n)-> STORING IN RECURSVE STACK SPACE!!
int findCarry(Node* head){
    Node *temp = head;
    // REACH BASE CASE IE NULL
    if(temp==nullptr){
        // carry=1 ie add 1 to the prev node
        return 1;
    }
    int carry=findCarry(temp->next);
    temp->data+=carry;
    if (temp->data < 10)
    {
        // ie return carry=0
        return 0;
    }
    else
    {
        // replace with 0 & send carry as 1
        temp->data=0;
        // carry = 1;
        return 1;
    }
}
Node *optimal(Node *head)
{
    int carry=findCarry(head);
    if(carry==1){
        // new node has to be added
        Node *newNode = new Node(carry);
        // prev points to last element
        newNode->next = head;
        head=newNode;   //move head here
        return head;
    }
    return head;
}

int main()
{
    int arr1[] = {1, 5, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node *node1 = convertArrToLL(arr1, n1);
    cout << "\nTraversing LL1: ";
    traverse(node1);
    cout << "\nAfter adding 1, LL is: ";
    // Node *summedLL1 = addOne(node1);
    Node *summedLL1 = optimal(node1);
    traverse(summedLL1);

    int arr2[] = {9, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *node2 = convertArrToLL(arr2, n2);
    cout << "\nTraversing LL2: ";
    traverse(node2);
    cout << "\nAfter adding 1, LL is: ";
    // Node *summedLL2 = addOne(node2);
    Node *summedLL2 = optimal(node2);
    traverse(summedLL2);

    return 0;
}