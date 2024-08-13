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

int countLen(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// TIME: O(n)->counting Length of LL  + O(n)->to find nth node == O(2n)
// SPACE: O(1)
Node *rotateRight(Node *head, int k)
{
    if (head == NULL || k==0)
    {
        return head;
    }

    int lengthOfLL = countLen(head);
    // if k==length of LL then return same LL
    if (k % lengthOfLL == 0)
    {
        return head;
    }

    // if k>length of LL then return k-LL
    k = k % lengthOfLL;

    Node *temp = head;
    // reach tail
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    // now tail ka next must point to head
    tail->next = head;

    // move to (lengthOfLL-k) steps
    int steps = lengthOfLL - k;
    int c = 0;
    while (temp != nullptr)
    {
        c++;
        if (c == steps)
        {
            break;
        }
        temp = temp->next;
    }
    // now temp ka next must be head
    head = temp->next;
    // now temp ka next must be null
    temp->next = nullptr;

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
    cout << "\nEnter value of k to rotate the LL= ";
    cin >> k;
    // enter k=1 and 2

    cout << "\nThe rotated linked list by " << k << " places is: ";
    Node *newNode = rotateRight(node, k);
    traverse(newNode);

    return 0;
}