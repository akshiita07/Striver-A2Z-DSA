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

// BRUTE FORCE: O(n->to push elem in stack)+O(n->to change elements)=O(2n)
// SPACE:O(n)->extra stack
Node *reverseDataOfLL(Node *head)
{
    stack<int> st;
    Node *temp = head;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// OPTIMISE: in place
// TIME: O(n)->single traversal         SPACE:O(1)->no extra space
Node *reverseLinks(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *backward = NULL;
    while (temp != nullptr)
    {
        backward = temp->prev;
        temp->prev = temp->next;
        temp->next = backward;
        temp = temp->prev; // beacuse we changed links
    }
    head = backward->prev;
    return head;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = convertArrToDoubleLL(arr, n);

    cout << "The Doubly LL is: " << endl;
    traverse(head);

    // Node *newLL = reverseDataOfLL(head);
    // cout << "The Doubly LL after changing data: " << endl;
    // traverse(newLL);

    Node *newLL2 = reverseLinks(head);
    cout << "\nThe Doubly LL after reversing links: " << endl;
    traverse(newLL2);

    return 0;
}