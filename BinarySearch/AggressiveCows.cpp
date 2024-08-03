#include <bits/stdc++.h>
using namespace std;

// fnc to check if all cows can be placed maintaining a given gap   TIME-O(n)
bool canCowBePlaced(vector<int> &stalls, int k, int gap)
{
    int n = stalls.size();
    // first cow always at index 0
    int noOfCows = 1;
    int positionCow = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if ((stalls[i] - positionCow) >= gap)
        {
            // i can place cow
            noOfCows++;
            positionCow = stalls[i];
        }
        else
        {
            continue;
            // check for next value of i if cow can be placed
        }
        // check if we achieved k??
        if (noOfCows >= k)
        {
            // i can place these no of cows successfully
            return true;
        }
    }
    return false;
}

// BRUTE FORCE:   TIME-O(n)-->fnc*O(max-min)-->loop
int brute_force(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int maxEle = *max_element(stalls.begin(), stalls.end());
    int minELe = *min_element(stalls.begin(), stalls.end());
    // place k cows consecutively with GAP=1 & find min dist bw any 2 cows
    // check if this is MAX possible configuration && are all k cows being placed?
    // place k cows consecutively with GAP=2 & find min dist bw any 2 cows
    // check if this is MAX possible configuration && are all k cows being placed?
    // place k cows consecutively with GAP=3 & find min dist bw any 2 cows
    // check if this is MAX possible configuration && are all k cows being placed?
    // place k cows consecutively with GAP=(MAX ELEMENT - MIN ELEMENT) & find min dist bw any 2 cows
    // check if this is MAX possible configuration && are all k cows being placed?

    // linear search
    for (int i = 1; i <= (maxEle - minELe); i++)
    {
        if (canCowBePlaced(stalls, k, i))
        {
            continue;
        }
        else
        {
            // not possible then return prev value ie ans
            return (i - 1);
        }
    }
    return -1;
}

// BINARY SEARCH:   TIME-O(n)-->fnc*O(log2(max-min))-->binary search
int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size(); 
    sort(stalls.begin(), stalls.end());
    int low = 1;        //start with gap of 1
    int high = stalls[n-1]-stalls[0];      //go upto max-min 
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;
        if (canCowBePlaced(stalls, k, mid))
        {
            ans=mid;
            // check for max ans
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;     //or return high
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};       //3
    int k = 4; // 4 aggreesive cows
    cout << "\nBRUTE FORCE: The MAXIMUM POSSIBLE MINIMUM distance between any 2 cows is: " << brute_force(stalls, k);
    cout << "\nThe MAXIMUM POSSIBLE MINIMUM distance between any 2 cows is: " << aggressiveCows(stalls, k);

    return 0;
}