#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
    }

    ListNode(int data1, ListNode *next1)
    {
        val = data1;
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

ListNode* insertNode(ListNode *head,int gcdVal){
    ListNode *temp=head;
    ListNode* newNode=new ListNode(gcdVal);
    newNode->next=temp->next;
    temp->next=newNode;
    return newNode;
}

ListNode *insertGreatestCommonDivisors(ListNode *head)
{
    ListNode *temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        int gcd=__gcd(temp->val,temp->next->val);
        temp=insertNode(temp,gcd);      //get pos of new node & cnt to its next
        temp=temp->next;
    }
    return head;
}

int main()
{
    int arr[] = {18, 6, 10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

    ListNode *newHead = insertGreatestCommonDivisors(node);
    cout << "\nTraversing LL with gcds added: ";
    traverse(newHead);
    // [18,6,6,2,10,1,3]

    return 0;
}