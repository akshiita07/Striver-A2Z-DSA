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
    Node *prev = NULL;
    while (temp != nullptr)
    {
        Node *forward = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forward;
    }
    head = prev; // head will point on prev
    return head;
}

Node *findKthNode(Node *head, int k)
{
    Node *kthNode;
    int c = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        c++;
        if (c == k)
        {
            kthNode = temp;
            break;
        }
        temp = temp->next;
    }
    return kthNode;
}

// TIME: O(n)->reversing groups + O(n)->finding kth node    ==  O(2n)
// SPACE: O(1)
Node *reverseKGroup(Node *head, int k)
{
    Node *temp = head;
    Node *lastNodeOfKthGroup = NULL;
    while (temp != nullptr)
    {
        // traverse upto kth node
        Node *kthNode = findKthNode(temp, k);

        if (kthNode == nullptr)
        {
            // if k no of elements are not available--> remains same
            if (lastNodeOfKthGroup)
            {
                // if exists then only perform:
                lastNodeOfKthGroup->next = temp;
            }
            break;
        }
        else
        {
            // BEFORE MAKING IT NULL-> PRESERVE NEXT NODE SO THAT WE CAN TRAVERSE TO THE NEXT GROUP
            Node *nextKthNode = kthNode->next;
            // SEPARATE THIS GROUP::node point to null to form an individual LL
            kthNode->next = nullptr;

            // NOW REVERSE THIS SORTED GROUP:
            reverseLL(temp); // pass head as temp & new head becomes this kthNode

            // check if it is first group if head==temp / later groups
            if (temp == head)
            {
                // bring head to this kth node
                head = kthNode;
                // kth node will be new head & head will become tail of this LL
            }
            else
            {
                // FOR LATER GROUPS:
                // make the kth        //point to new node of group
                lastNodeOfKthGroup->next = kthNode;
            }

            // temp also at tail of LL

            // REMEBER THIS LAST NODE OF GROUP SO THAT IT CAN POINT TO NEXT NODE OF THIS GROUP-> STORE IT
            lastNodeOfKthGroup = temp;

            // bring temp to new groups head:
            temp = nextKthNode;
        }
    }
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

    int k;
    cout << "\nEnter value of k ie lesser/equal to " << n << " to reverse the nodes= ";
    cin >> k;
    // enter k=2 and 3

    cout << "\nThe reversed linked list " << k << " at a time is: ";
    Node *newNode = reverseKGroup(node, k);
    traverse(newNode);

    return 0;
}