#include <bits/stdc++.h>
using namespace std;

class ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TIME: O(max(n1,n2))
// SPACE: O(max(n1,n2))->only for storing ans not for solving
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ptr1 = l1;
    ListNode *ptr2 = l2;

    ListNode *dummy = new ListNode(-1);
    ListNode *mover = dummy;

    int carry = 0;
    // stop only when both r null
    while (ptr1 != nullptr || ptr2 != nullptr)
    {
        int sum = carry;
        if (ptr1 != nullptr)
        {
            sum += ptr1->data;
        }
        if (ptr2 != nullptr)
        {
            sum += ptr2->data;
        }
        ListNode *newNode = new ListNode(sum % 10);
        carry = sum / 10;
        mover->next = newNode;
        mover = newNode;

        if (ptr1 != nullptr)
        {
            ptr1 = ptr1->next;
        }
        if (ptr1 != nullptr)
        {
            ptr2 = ptr2->next;
        }
    }
    if (carry == 1)
    {
        // for a leftovr carry
        ListNode *newNode = new ListNode(1);
        mover->next = newNode;
    }
    ListNode *head = dummy->next;
    return head;
}

int main()
{
    int l1[] = {2, 4, 3};
    int l2[] = {5, 6, 4};

    return 0;
}