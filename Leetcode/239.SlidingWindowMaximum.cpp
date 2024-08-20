#include <bits/stdc++.h>
using namespace std;

// TIME: O(n-k)*O(k)   ==  O(n^2)
// SPACE: O(n-k)->to store answer
vector<int> bruteforce(vector<int> &nums, int k)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < (n - k); i++)
    {
        int maxEle = nums[i];
        for (int j = i; j < i + k - 1; j++)
        {
            // choose max out of these k elements
            if (nums[j] > maxEle)
            {
                maxEle = nums[j];
            }
        }
        ans.push_back(maxEle);
    }
    return ans;
}

vector<int> better(vector<int> &nums, int k)
{
    vector<int> ans;
    int n = nums.size();
    queue<int> qu;
    for (int i = 0; i < k; i++)
    {
        // push 1st k elem in queue:
        qu.push(nums[i]);
    }
    for (int i = k; i < n; i++)
    {
        // find max out of queue:
        int qSize = qu.size();
        int maxElem = INT_MIN;
        for (int j = 0; j < qSize; j++)
        {
            int ele = qu.front();
            if (ele > maxElem)
            {
                maxElem = ele;
            }
            qu.pop();
            qu.push(ele);
        }
        ans.push_back(maxElem);
        // pop the first elem out of queue & add next element
        qu.pop();
        qu.push(nums[i]);
    }
    // for last element:
    int qSize = qu.size();
    int maxElem = INT_MIN;
    for (int j = 0; j < qSize; j++)
    {
        int ele = qu.front();
        if (ele > maxElem)
        {
            maxElem = ele;
        }
        qu.pop();
        qu.push(ele);
    }
    ans.push_back(maxElem);
    return ans;
}

// TIME: O(n)->for loop + O(n)->while loop atmax n times        == O(2n)
// SPACE: O(n-k)->to return answer   + O(k)->for dequeue
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    int n = nums.size();
    deque<int> dq;
    for(int i=0;i<n;i++){
        if(dq.empty()==false && dq.front()<=(i-k)){
            // cannot stay as window exceeded
            dq.pop_front();
        }
        while(dq.empty()==false && nums[dq.back()]<=nums[i]){
            // do not store smaller elements
            dq.pop_back();
        }
        dq.push_back(i);
        // add answer in list
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }

    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    // Output: [3,3,5,5,6,7]
    // vector<int> ans = bruteforce(nums, k);
    // vector<int> ans = better(nums, k);
    vector<int> ans = maxSlidingWindow(nums, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}