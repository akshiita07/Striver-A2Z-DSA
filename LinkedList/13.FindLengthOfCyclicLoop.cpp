#include <bits/stdc++.h>
using namespace std;

// If there is no cycle, return 0, otherwise return the length of the cycle.

// Using hash map
// TIME: O(n*2*1)-> traversing LL & unordered map so 2*O(1) e 2 opeartions of map->find/value
// SPACE: O(n)->storing all nodes
int brute_force(Node *head)
{
    unordered_map<Node *, int> hashMap;
    // store node & this i
    Node *temp = head;
    int i = 1;
    while (temp != nullptr)
    {
        // first check if already exists in map
        if (hashMap.find(temp) != hashMap.end())
        {
            // found so cycle exists
            int value = hashMap[temp];
            return (i - value);
        }
        // else add it
        hashMap[temp] = i;
        i++;
        temp = temp->next; // move temp!! 😭
    }
    return 0; // no cycle exists so return 0
}

// OPTIMLA USING TORTOISE & HARE APPROACH
// TIME: O(n+n)=O(2n)
// SPACE: O(1)
int findLength(Node *slow, Node *fast)
{
    // TIME: O(length of loop) =O(n)
    int count = 1;
    fast = fast->next;
    while (fast != slow)
    {
        count++;
        fast = fast->next;
    }
    return count;
}
int lengthOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        // TIME:O(n)

        // move slow by 1
        slow = slow->next;
        // move fast by 2
        fast = fast->next->next;

        // if they collide then cycle exists
        if (slow == fast)
        {
            // cycle exists
            // now take a counter & move fast to find length
            return findLength(slow, fast);
        }
    }
    return 0; // no cycle exists so return 0
}