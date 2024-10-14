#include <bits/stdc++.h>
using namespace std;

long long maxKelements(vector<int> &nums, int k)
{
    // choose largest element of array
    // add this element to score
    // replace this element by ceil(elem/3)

    priority_queue<int> maxHeap(nums.begin(), nums.end());
    long long score=0;
    // k operations
    for(int i=0;i<k;i++){
        // get largest element from maxHeap
        int maxEle=maxHeap.top();
        // pop it from heap
        maxHeap.pop();
        // add elem to score
        score+=maxEle;
        // replace element
        // int replacedVal=ceil(maxEle/3);
        int replacedVal=(maxEle+2) / 3;     //ceil
        // insert this new elemen in heap
        maxHeap.push(replacedVal);
    }
    return score;
}

int main()
{
    vector<int> nums={1,10,3,3,3};
    int k=3;
    cout<<"\nMaximum possible score after applying "<<k<<" operations is: "<<maxKelements(nums,k);

    return 0;
}