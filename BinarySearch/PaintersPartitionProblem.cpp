#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int> &boards, int k, int maxTimeReqd)
{
    int noOfPainters = 1;
    int time = 0;

    for (int i = 0; i < boards.size(); i++)
    {
        if ((time + boards[i]) <= maxTimeReqd)
        {
            time += boards[i];
        }
        else
        {
            // time exceed
            noOfPainters++;
            time = boards[i];
        }
    }
    return noOfPainters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfPainters = countPainters(boards, k, mid);
        if (noOfPainters > k)
        {
            // zyada painters reqd-->range badhao
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> boards = {2, 1, 5, 6, 2, 3};
    int k = 2;
    cout<<"The min amount of time reqd to paint board using "<<k<<" painters: "<<findLargestMinDistance(boards,k);

    return 0;
}