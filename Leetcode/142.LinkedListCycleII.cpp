#include <bits/stdc++.h>
using namespace std;

//  return the node where the cycle begins, if a cycle exists, else return 'NULL'

// BRUTE FORCE
// TIME: O(n)->traversal*O(2*1)->2 operations on unordered map of O(1)
// SPACE: O(n)->storing all nodes in map
Node *brute_force(Node *head)
{
    unordered_map<Node *, int> hashMap;
    Node *temp = head;
    while (temp != nullptr)
    {
        // check if preexists
        if (hashMap.find(temp) != hashMap.end())
        {
            // found return this
            // yes cycle exists so return starting node
            return temp;
        }
        hashMap[temp] = 1;
        temp = temp->next;
    }
    // no cycle exists so return NULL
    return NULL;
}

// OPTIMAL- TORTOISE HARE APPROACH
// TIME: O()
// SPACE: O()
Node *firstNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            // yes cycle exists so return starting node

            // bring slow to head of LL
            slow = head;
            // fast must remain at this collission point
            // now move both slow & fast by 1 step simultaneously
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            // slow==fast so return this node
            return slow;    //or can even return fast
        }
    }
    // no cycle exists so return NULL
    return NULL;
}