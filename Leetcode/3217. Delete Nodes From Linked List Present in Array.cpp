/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Return head of modified linked list after removing all nodes from LL
        // that have a value that exists in array nums

        // for each elem in nums array check if heads value=that elem then
        // delete that node

        // take a set & place nums in it so that lookup is in O(1) time
        unordered_set<int> arrayNums;
        for (auto it : nums) {
            arrayNums.insert(it);
        }
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (temp != nullptr) {
            // delet it
            if (arrayNums.find(temp->val) != arrayNums.end()) {
                // delete this node
                prev->next = temp->next;
                temp = prev->next;
            } else {
                // move prev to temp
                prev = temp;
                // move temp to next of prev always
                temp = temp->next;
            }
        }

        head = dummy->next;
        // free up dummy nodes memory
        delete dummy;
        return head;
    }
};
