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

bool brute_force(Node *head)
{
    vector<int> list;
    Node *temp = head;
    while (temp != nullptr)
    {
        list.push_back(temp->data);
        temp = temp->next;
    }
    vector<int> listReversed = list;
    reverse(listReversed.begin(), listReversed.end());

    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == listReversed[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
    // return true if palindrome
    // return false if NOT a  palindrome
}

// USING STACK
// TOTAL TIME: O(n+n)=O(2n)
// TOTAL SPACE: O(n)->using stack to store all elements
bool brute_force_stack(Node *head)
{
    stack<int> st;
    Node *temp = head;
    // store elements in stack in LIFO:
    while (temp != nullptr)
    {
        // TIME: O(n)
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head; // return back
    while (temp != nullptr || !st.empty())
    {
        // TIME: O(n)
        int elem = st.top();
        st.pop();
        if (elem == temp->data)
        {
            temp = temp->next;
        }
        else
        {
            // return false if NOT a  palindrome
            return false;
        }
    }
    return true;
    // return true if palindrome
}

// for optimal approach:
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
    return prev; // new head
}

// OPTIMALL
// TOTAL TIME: O(n/2+n/2+n/2+n/2)=O(2n)
// TOTAL SPACE: O(1)->NO EXTRA SPACE REQD
bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        // empty LL & LL with only 1 element is always a palindrome
        return true;
    }

    // recognise where does the first half end
    // TORTOISE & HARE APPROACH TO FIND MIDDLE ELEMENT OF LL:
    Node *slow = head;
    Node *fast = head;
    // TIME:O(n/2)->finding mid of LL
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        // for odd no of LL:stop at last pos:  fast->next!=nullptr
        // for even no of LL: stop at second last pos:  fast->next->next!=nullptr
        fast = fast->next->next; // fast moves by 2 steps
        slow = slow->next;       // slow moves by 1 step
    }
    // slow will point to end of 1st half:

    // after this first half reverse links
    Node *headOfSecondHalf = slow->next;
    // code to reverse 2nd half:
    Node *newHeadOfReverseLL = reverseLL(headOfSecondHalf);  // TIME:O(n/2)->reversing just half of LL
    // now ptr points to head of 2nd half of LL
    Node *second = newHeadOfReverseLL;

    // check & compare:
    Node *first = head;
    // TIME:O(n/2)->comparing only half of nodes
    while (first != nullptr && second != nullptr)
    {
        if (first->data == second->data)
        {
            first = first->next;
            second = second->next;
        }
        else
        {
            // not same so end
            // return false if NOT a  palindrome
            Node *changeHead = reverseLL(newHeadOfReverseLL);
            return false;
        }
    }
    // do not alter current data & convert it back to original form
    Node *changeHead = reverseLL(newHeadOfReverseLL); // TIME:O(n/2)->reversing just half of LL
    // return true if palindrome
    return true;
}

int main()
{
    // LL1:         true
    int arr1[] = {1, 2, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    Node *node1 = convertArrToLL(arr1, n1);
    cout << "\nTraversing LL1: ";
    traverse(node1);
    cout << "\nBRUTE FORCE USING LIST: Is LL1 a palindrome LL?: " << brute_force(node1);
    cout << "\nBRUTE FORCE USING STACK: Is LL1 a palindrome LL?: " << brute_force_stack(node1);
    // isPalindrome(node1);
    cout << "\nIs LL1 a palindrome LL?: " << isPalindrome(node1);

    cout << endl;

    // LL2:         false
    int arr2[] = {1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *node2 = convertArrToLL(arr2, n2);
    cout << "\nTraversing LL2: ";
    traverse(node2);
    cout << "\nBRUTE FORCE USING LIST: Is LL2 a palindrome LL?: " << brute_force(node2);
    cout << "\nBRUTE FORCE USING STACK: Is LL2 a palindrome LL?: " << brute_force_stack(node2);
    cout << "\nIs LL2 a palindrome LL?: " << isPalindrome(node2);

    return 0;
}