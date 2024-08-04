#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: TIME:O(k*n + n)
double brute_force(vector<int> &arr, int k)
{
    int n = arr.size();

    // array that includes how many gaps for adding new gas stations
    vector<int> howManySpaces((n - 1), 0); // initialised with 0

    // for each gas station
    for (int i = 1; i <= k; i++)
    {
        // where to place the gas station?--> where dist is MAX
        double maxDiff = -1;
        int maxDiffIndex = -1;

        for (int j = 0; j < n - 1; j++) // till n-1 only because no j+1 would exist for n
        {
            // find max diff
            double sectionDiff = ((arr[j + 1] - arr[j]) / (double)(howManySpaces[j] + 1));
            // find occurrening index
            if (sectionDiff > maxDiff)
            {
                maxDiff = sectionDiff; // maxDiff=max(maxDiff,sectionDiff);
                maxDiffIndex = j;
            }
        }

        // we have max diff & index
        howManySpaces[maxDiffIndex]++;
    }

    double ans = -1;
    // go across each section & find max diff
    for (int i = 0; i < n - 1; i++) // till n-1 only because no i+1 would exist for n
    {
        double sectionDiff = ((arr[i + 1] - arr[i]) / (double)(howManySpaces[i] + 1));
        if (sectionDiff > ans)
        {
            ans = sectionDiff;
        }
    }
    return ans;
}

// priority queue stores top element as MAX element:
// priority queue: (maxDiff,maxIndex)
// TIME:O(n*log2(n)-->to push in pq + k*log2(n)-->for gas stations)
// SPACE:O(n-1)-->for pq
double betterSoln(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<pair<double, int>> pq;
    // array that includes how many gaps for adding new gas stations
    vector<int> howManySpaces((n - 1), 0); // initialised with 0

    // insert all sections in pq
    for (int i = 0; i < n - 1; i++)
    {
        double maxDiff = arr[i + 1] - arr[i];
        int maxDiffIndex = i;
        pq.push({maxDiff, maxDiffIndex}); // as a pair
    }

    for (int i = 1; i <= k; i++)
    {
        // place gas stations
        auto topEle = pq.top();
        pq.pop();
        int index = topEle.second;
        howManySpaces[index]++;

        // push new diff
        double maxDiff = (arr[index + 1] - arr[index]) / (double)(howManySpaces[index] + 1);
        int maxDiffIndex = index;
        pq.push({maxDiff, maxDiffIndex}); // as a pair
    }
    return pq.top().first; // max diff
}

// reduce space complexity
// BINARY SEARCH: TIME-O()
int noOfGasStations(vector<int> &arr,long double dist){
    int count = 0;
    int n=arr.size();
    for (int i = 1; i <n ; i++)
    {
        int noBetween = ((arr[i] - arr[i - 1])/dist);
        if ((arr[i] - arr[i - 1])==(dist*noBetween))
        {
            // NOT exactly   divisible
            noBetween--;
        }
        count+=noBetween;
    }

    return count;
}
double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();

    // range
    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6; // 10 ^ -6
    while ((high - low) > diff)
    {
        long double mid = (low + high) / (2.0);
        int count = noOfGasStations(arr, mid);
        if (count > k)
        {
            // not possible so inc dist
            low = mid;
        }
        else
        {
            // possible
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 6; // 0.5
    cout << "\nBRUTE FORCE: The min dist bw any 2 adjacent gas stations is: " << brute_force(arr1, k1);
    cout << "\npriority_queue: The min dist bw any 2 adjacent gas stations is: " << betterSoln(arr1, k1);
    cout << "\nThe min dist bw any 2 adjacent gas stations is: " << minimiseMaxDistance(arr1, k1);
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k2 = 1; // 1
    cout << "\nThe min dist bw any 2 adjacent gas stations is: " << minimiseMaxDistance(arr2, k2);

    return 0;
}