#include <bits/stdc++.h>
using namespace std;

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
int getDecimalValue(ListNode *head)
{
    // first form the decimal number as string
    string num = "";
    ListNode *temp = head;
    while (temp != nullptr)
    {
        // cout<<temp->val<<" ";
        num += to_string(temp->val);
        temp = temp->next;
    }
    // convert num to integer
    cout << "\nNumber is: " << num;

    // int binary=stoi(num);
    // cout<<"\nNumber in integer is: "<<binary;

    // convert from binary to decimal
    // multiply by 2^power * digit
    int dec = 0;
    int base = 1;
    for (int i = num.length() - 1; i >= 0; i--)
    {
        if (num[i] == '1')
        {
            dec += base;
        }
        base = base * 2;
    }
    return dec;
}

int main()
{

    return 0;
}