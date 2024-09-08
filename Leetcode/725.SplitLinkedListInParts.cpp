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

int findLengthLL(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// void myBrute()
// {
//     if (lenLL <= k)
//     {
//         while (k != 0)
//         {
//             ListNode *temp = head;
//             if (temp == nullptr)
//             {
//                 ans.push_back(nullLL); // push null
//             }
//             else
//             {
//                 ans.push_back(temp); // push this node itself
//                 head = head->next;
//                 temp->next = nullptr;
//             }
//             k--;
//         }
//     }
//     else
//     {
//         // check partions & first partions must be greater:
//         float checkDiv = float(lenLL) / k;
//         cout << "\nDivision gives: " << checkDiv;

//         if (checkDiv > k)
//         {
//             // first half will have k+1 values
//             while ((k + 1) > 0)
//             {
//                 ListNode *temp = head;
//                 ans.push_back(temp);
//                 head = head->next;
//                 temp->next = nullptr;
//                 k--;
//             }
//         }
//         else
//         {
//             while (k > 0)
//             {
//                 ListNode *temp = head;
//                 ans.push_back(temp);
//                 head = head->next;
//                 temp->next = nullptr;
//                 k--;
//             }
//         }
//     }
// }

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    // split the linked list into k consecutive linked list parts
    //  length of each part should be as equal as possible
    // no two parts should have a size differing by more than one
    // parts occurring earlier should always have a size greater than or equal to parts occurring later
    vector<ListNode *> ans;     //add only heads of partion lists!!
    int lenLL = findLengthLL(head);
    // ListNode *nullLL = nullptr;

    // if length of ll is less than k then add individual elements & remaining would be null
    int sizeOfPartition = lenLL / k;
    int extraNodes = lenLL % k; // to be added in first halfs

    //start from head of LL:
    ListNode *temp = head;

    for (int i = 0; i < k; i++)
    {
        //start from current partition:
        ListNode *partitionHead = temp;
        int currentPartitionSize = sizeOfPartition;
        if (i < extraNodes)
        {
            currentPartitionSize += 1;
        }
        for (int j = 0; j < (currentPartitionSize-1); j++)
        {
            // move thru partition for currentpartiton-1 size:
            if (temp == nullptr)
            {
                break;
            }
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            // next partition starts from here:
            ListNode *nextPart = temp->next;
            // disconnect diff parts:
            temp->next = nullptr;
            // start temp from next part
            temp = nextPart;
        }
        ans.push_back(partitionHead);
    }

    cout << "\nThe output list after splitting is: ";
    for (auto it : ans)
    {
        if (it == nullptr)
        {
            cout << "[]" << " ";
        }
        else
        {
            // this it is ListNode* so print its data
            cout << it->val << " ";
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *node = convertArrToLL(arr, n);
    cout << "\nTraversing LL: ";
    traverse(node);

    int k = 3;
    // int k = 5;
    splitListToParts(node, k);
    // Output: [[1,2,3,4],[5,6,7],[8,9,10]]

    return 0;
}