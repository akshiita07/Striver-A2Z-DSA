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
    int countLen(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int lengthOfLL = countLen(head);
        // if k==length of LL then return same LL
        if (k % lengthOfLL == 0) {
            return head;
        }

        // if k>length of LL then return k-LL
        k = k % lengthOfLL;
        // find tail & make it point to head
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = head;

        // move length-k steps
        int steps = lengthOfLL - k;
        ListNode* temp = head;
        int c = 0;
        while (temp != nullptr) {
            c++;
            if (c == steps) {
                break;
            }
            temp = temp->next;
        }
        // new head
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};
