#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val1)
    {
        val = val1;
        next = nullptr;
    }

    ListNode(int val1, ListNode *next1)
    {
        val = val1;
        next = next1;
    }
};

ListNode *convertArrToLL(int arr[], int n)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;
    for (int i = 1; i < n; i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverse(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

// BRUTE FORCE-> DATA REPLACEMENT
// TIME:O(n/2+n/2+n)=O(2n)
// SAPCE:O(n)->using array to store elements
ListNode *brute_force(ListNode *head)
{
    // if no element or only single element
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    vector<int> listOfElem;

    ListNode *temp = head;
    // TIME:O(n/2) as skipping elements
    while (temp != nullptr && temp->next != nullptr)
    {
        listOfElem.push_back(temp->val);
        // move by 2 spaces for all odd indices
        temp = temp->next->next;
    }
    // for odd length LL: last elem will not be added as temp->next==nullptr so
    if (temp)
    {
        listOfElem.push_back(temp->val);
    }

    temp = head->next; // start from 1st even index
    // TIME:O(n/2) as skipping elements
    while (temp != nullptr && temp->next != nullptr)
    {
        listOfElem.push_back(temp->val);
        // move by 2 spaces for all even indices
        temp = temp->next->next;
    }
    // for even length LL: last elem will not be added as temp->next==nullptr so
    if (temp)
    {
        listOfElem.push_back(temp->val);
    }

    // replace LL data with first odd list then even list
    temp = head;
    int i = 0;
    // TIME:O(n)
    while (temp != nullptr)
    {
        temp->val = listOfElem[i];
        i++;
        temp = temp->next;
    }
    return head;
}

// changing links
// TIME: O(n)
// SPACE: O(1)-> no extra space reqd
ListNode *oddEven(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *odd = head;            // at first
    ListNode *even = head->next;     // from even index
    ListNode *evenHead = head->next; // store this or else we wont be able to access

    // even is always ahead of odd so check only for even
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;        //move to this next one
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode *node1 = convertArrToLL(arr1, n1);
    cout << "\nTraversing LL: ";
    traverse(node1);
    // ListNode *newNode1 = brute_force(node1);
    ListNode *newNode1 = oddEven(node1);
    cout << "\nTraversing new LL with odds first then even: ";
    traverse(newNode1);

    int arr2[]={2,1,3,5,6,4,7};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    ListNode* node2=convertArrToLL(arr2,n2);
    cout<<"\nNODE2--> Traversing LL: ";
    traverse(node2);
    ListNode* newNode2=oddEven(node1);
    cout<<"\nNODE2--> Traversing new LL with odds first then even: ";
    traverse(newNode2);

    return 0;
}