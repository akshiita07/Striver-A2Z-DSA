#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data1)
    {
        data = data1;
        next = nullptr;
    }

    ListNode(int data1, ListNode *next1)
    {
        data = data1;
        next = next1;
    }
};

class Solution
{
public:
    //  TOTAL TIME: O(n*2*1)->unordered map so O(1) & 2 operations of map
    //  SPACE: O(n)-> to store in unordered map
    bool brute_force(ListNode *head)
    {
        ListNode *temp = head;
        unordered_map<ListNode *, int> hashMap;

        while (temp != nullptr)
        {
            if (hashMap.find(temp) != hashMap.end())
            {
                // ie found node so cycle exists
                return true;
            }
            hashMap[temp] = 1;
            temp = temp->next;
        }
        return false;
    }

    // USING TORTOISE & HARE ALGO:
    //  TOTAL TIME: O(n)->looping until fast==slow
    //  SPACE: O(1)
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        // slow moves 1
        // fast moves 2

        // if slow & fast meets then a loop exists for sure
        // remember: write fast != nullptr first then next condition:
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow==fast)
            {
                // cycle exists
                return true;
            }
        }
        return false;
    }
};