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

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
{
    // given m*n dimensions of matrix ie m rows & n columns
    // Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1
    vector<vector<int>> ans(m, vector<int>(n,-1)); // initialise with -1
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    ListNode *temp = head;

    // while elements r left:
    while (top <= bottom && left <= right && temp!=nullptr)
    {
        // start from 1st row
        for (int i = left; i <= right  && temp!=nullptr; i++)
        {
            ans[top][i] = temp->val;
            temp = temp->next;
        }
        // first row done
        top++;
        for (int i = top; i <= bottom  && temp!=nullptr; i++)
        {
            ans[i][right] = temp->val;
            temp = temp->next;
        }
        // last colm done:
        right--;
        // check cnd again
        if (top <= bottom)
        {
            for (int i = right; i >= left  && temp!=nullptr; i--)
            {
                ans[bottom][i] = temp->val;
                temp = temp->next;
            }
            bottom--;
        }
        // check cnd again
        if (top <= bottom)
        {
            for (int i = bottom; i >= top  && temp!=nullptr; i--)
            {
                ans[i][left] = temp->val;
                temp = temp->next;
            }
            left++;
        }
    }
    cout<<"\nThe spiral matrix is: ";
    for(auto row:ans){
        cout<<"[";
        for(auto it:row){
            cout<<it<<" ";
        }
        cout<<"]";
    }
    return ans;
}

int main()
{
    int arr[] = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
    int sizeOfLL = sizeof(arr) / sizeof(arr[0]);
    ListNode *node = convertArrToLL(arr, sizeOfLL);
    cout << "\nTraversing LL: ";
    traverse(node);
    int m = 3;
    int n = 5;

    spiralMatrix(m, n, node);
    return 0;
}