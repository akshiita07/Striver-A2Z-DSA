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

// BRUTE FORCE USING DATA SWAPPING
Node *brute_force(Node *head)
{
    vector<int> list;
    Node *temp = head;
    while (temp != nullptr)
    {
        list.push_back(temp->data);
        temp = temp->next;
    }

    reverse(list.begin(), list.end());

    // add reversed LL into list
    temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        temp->data = list[i];
        i++;
        temp = temp->next;
    }
    return head;
}

// BRUTE FORCE USING ADDITONAL STACK
// Total TIME: O(n+n)=O(2n)
// SPACE: O(n)-> stack
Node *brute_force_stack(Node *head)
{
    stack<int> st;
    Node *temp = head;
    // TIME: O(n)
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    // add reversed LL into list
    temp = head;
    // TIME: O(n)
    while (temp != nullptr)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node *reverseList_Iterative(Node *head)
{
    // read end of LL first:
    Node *temp = head;
    Node *prev = NULL;
    while (temp != nullptr)
    {
        Node *forward = temp->next;
        temp->next = prev;
        forward->next = temp;
        prev = temp;
        temp = forward;
    }
    // new head will now point on prev
    head=prev;
    return head;
}

// TIME: O(n)->traversing thru all nodes
// SPACE: O(n)->recursive stack space
Node *reverseList_Recursive(Node *head)
{
    // base case: if i have a single node then no need to reverse it
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* newHead=reverseList_Recursive(head->next);
    // code to reverse any 2 nodes:
    Node* temp=head;
    Node* forward=temp->next;
    temp->next=NULL;
    forward->next=temp;
    return newHead; //new head
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

    // Node* newLL=brute_force(node);
    // Node *newLL = brute_force_stack(node);
    // Node *newLL = reverseList_Iterative(node);
    Node *newLL = reverseList_Recursive(node);
    cout << "\nTraversing REVERSED LL: ";
    traverse(newLL);

    return 0;
}