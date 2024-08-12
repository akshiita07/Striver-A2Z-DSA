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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return NULL;
        }
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != nullptr) {
            if (temp->val == val) {
                ListNode* forward = temp->next;
                if (temp == head) {
                    head = forward;
                }
                if (prev != NULL) {
                    prev->next = forward;
                }
                delete temp;
                temp = forward;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};