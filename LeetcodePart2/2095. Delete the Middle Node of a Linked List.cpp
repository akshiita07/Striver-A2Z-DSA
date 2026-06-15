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
    ListNode* deleteElement(ListNode* head, ListNode* nodeToDelete) {
        int c = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != nullptr) {
            if (temp == nodeToDelete) {
                if (c == 0) {
                    // delete 1st index
                    head = head->next;
                    temp->next = nullptr;
                    delete temp;
                    return head;
                }
                prev->next = temp->next;
                delete temp;
                return head;
            }
            c++;
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* newLL = NULL;
        // for odd length: fast->next=nullptr
        // for even length: fast-=nullptr
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        newLL = deleteElement(head, slow); // middle element
        return newLL;
    }
};
