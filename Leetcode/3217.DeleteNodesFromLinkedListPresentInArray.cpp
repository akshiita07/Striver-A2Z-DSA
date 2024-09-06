#include <bits/stdc++.h>
using namespace std;

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

ListNode *deleteNode(ListNode *head, ListNode *node)
{
    if (head == nullptr)
    {
        cout << "\nNo elements r present in LL";
        return NULL;
    }
    ListNode *temp = head;
    ListNode *mover = nullptr;
    while (temp != nullptr)
    {
        if (temp->val == node->val)
        {
            // ie node to be deleted

            // check if is it the head
            if (mover == nullptr)
            {
                cout << "\nDeleting head of LL";
                head = head->next;
                temp->next = nullptr;
                delete temp;
                return head;
            }
            else
            {
                // any in between node
                mover->next = temp->next;
                delete temp;
                return head;
            }
        }
        mover = temp;
        temp = temp->next;
    }
    return head;
}

// 2 loops so )(n^2)
ListNode *brute_force(vector<int> &nums, ListNode *head)
{
    // Return head of modified linked list after removing all nodes from LL that have a value that exists in array nums

    // for each elem in nums array check if heads value=that elem then delete that node
    for (int i = 0; i < nums.size(); i++)
    {
        ListNode *temp = head;
        while (temp != nullptr)
        {
            if (temp->val == nums[i])
            {
                // delete this node
                head = deleteNode(head, temp);
                temp = head;
                // if a node is deletd then restart traversal from new head to check for more such entries
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    return head;
}

ListNode *better(vector<int> &nums, ListNode *head)
{
    // Return head of modified linked list after removing all nodes from LL that have a value that exists in array nums

    // for each elem in nums array check if heads value=that elem then delete that node

    // take a set & place nums in it so that lookup is in O(1) time
    unordered_set<int> arrayNums;
    for (auto it : nums)
    {
        arrayNums.insert(it);
    }
    ListNode *temp = head;
    while (temp != nullptr)
    {
        if (arrayNums.find(temp->val) != arrayNums.end())
        {
            // delete this node
            head = deleteNode(head, temp);
            temp = head;
            // if a node is deletd then restart traversal from new head to check for more such entries
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}


// TIME: O(n)
// SPACE: O()
ListNode *modifiedList(vector<int> &nums, ListNode *head)
{
    // Return head of modified linked list after removing all nodes from LL that have a value that exists in array nums

    // for each elem in nums array check if heads value=that elem then delete that node

    // take a set & place nums in it so that lookup is in O(1) time
    unordered_set<int> arrayNums;
    for (auto it : nums)
    {
        arrayNums.insert(it);
    }
    ListNode *temp = head;
    ListNode *dummy = new ListNode(0);
    dummy->next=head;
    ListNode *prev = dummy;

    while (temp != nullptr)
    {
        // delet it
        if (arrayNums.find(temp->val) != arrayNums.end())
        {
            // delete this node
            prev->next = temp->next;
            delete temp;
        }
        else
        {
            // move prev to temp
            prev = temp;
        }
        // move temp to next of prev always
        temp = prev->next;
    }

    head = dummy->next;
    // free up dummy nodes memory
    delete dummy;
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL initially: ";
    traverse(node);

    vector<int> nums = {1, 2, 3}; // nodes to be removed from LL

    ListNode *newNode = modifiedList(nums, node);
    cout << "\nTraversing modified LL: ";
    traverse(newNode);

    cout << endl;

    int arr1[] = {1, 2, 1, 2, 1, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode *node1 = convertArrToLL(arr1, n1);
    cout << "\nTraversing LL initially: ";
    traverse(node1);

    vector<int> nums1 = {1}; // nodes to be removed from LL

    ListNode *newNode1 = modifiedList(nums1, node1);
    cout << "\nTraversing modified LL: ";
    traverse(newNode1);

    return 0;
}
