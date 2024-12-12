#include <bits/stdc++.h>
using namespace std;

long long pickGifts(vector<int> &gifts, int k)
{
    // use a max heap
    priority_queue<int> maxHeap(gifts.begin(), gifts.end());

    // for each second:
    while (k > 0)
    {
        int maxGift=maxHeap.top();     //top elem stores max gifts
        // return floor of its square root:
        maxHeap.pop();
        int newGift=floor(sqrt(maxGift));
        // push this new gift value i heap:
        maxHeap.push(newGift);
        k--;        //decrement second
    }

    long long totalRemaining=0;
    while(!maxHeap.empty()){
        // add all values of heap:
        totalRemaining+=maxHeap.top();
        maxHeap.pop();
    }
    return totalRemaining;
}

int main()
{
    vector<int> gifts = {25, 64, 9, 4, 100};
    int k = 4;
    cout << "\nNumber of gifts remaining are: " << pickGifts(gifts, k);

    return 0;
}