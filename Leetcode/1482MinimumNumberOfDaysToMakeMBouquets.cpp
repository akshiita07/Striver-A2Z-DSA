#include <bits/stdc++.h>
using namespace std;

// fnc to calculate if flower is bloomed & adjacents or not
bool isPossible_forBruteForce(vector<int> &bloomDay, int day, int m, int k)
{
    int count = 0;
    int n = bloomDay.size();
    int noOfBouquet = 0;

    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= day)
        {
            // flower is bloomed
            count++;
        }
        else
        {
            // unBloomed
            noOfBouquet += (count) / k;
            count = 0; // when count=0 ie it encounters a NOT bloomed flower
        }
    }
    noOfBouquet += (count) / k;

    if (noOfBouquet >= m)
    {
        // possible
        return true;
    }
    else
    {
        // not possible
        return false;
    }
}

// BRUTE FORCE:     time:O((max-min+1)-->loop * (n)-->to check if possible)
int brute_force(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    if ((m * k > n))
    {
        // not enough flowers available to make this amount
        return -1;
    }

    // take min element from array to bloom 1 flower
    int minEle = *min_element(bloomDay.begin(), bloomDay.end());
    int maxEle = *max_element(bloomDay.begin(), bloomDay.end());
    for (int i = minEle; i <= maxEle; i++)
    {
        if (isPossible_forBruteForce(bloomDay, i, m, k))
        {
            return i;
        }
    }

    return -1;
}

// fnc to calculate if flower is bloomed & adjacents or not
int isPossible(vector<int> &bloomDay, int day, int m, int k)
{
    int count = 0;
    int n = bloomDay.size();
    int noOfBouquet = 0;

    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= day)
        {
            // flower is bloomed
            count++;
        }
        else
        {
            // unBloomed
            noOfBouquet += (count) / k;
            count = 0; // when count=0 ie it encounters a NOT bloomed flower
        }
    }
    noOfBouquet += (count) / k;

    return noOfBouquet;
}

// BINARY SEARCH:     time:O(n-->isPossible fnc * log(max-min+1)-->binary search)
int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    if ((m * k > n))
    {
        // not enough flowers available to make this amount
        return -1;
    }

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int count = isPossible(bloomDay, mid, m, k);
        // check if adjacent flowers r bloomed
        if (count >= m)
        {
            ans = mid;
            high = mid - 1; // for MIN val
        }
        else if (count < m)
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout << "\nBRUTE FORCE: The minimum no of days reqd to make " << m << " bouquets with " << k << " adjacent flowers are: " << brute_force(bloomDay, m, k);
    cout << "\nThe minimum no of days reqd to make " << m << " bouquets with " << k << " adjacent flowers are: " << minDays(bloomDay, m, k);

    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    int m1 = 3;
    int k1 = 2;
    cout << "\nThe minimum no of days reqd to make " << m1 << " bouquets with " << k1 << " adjacent flowers are: " << minDays(bloomDay1, m1, k1);

    vector<int> bloomDay2 = {7,7,7,7,12,7,7};
    int m2 = 2;
    int k2 = 3;
    cout << "\nThe minimum no of days reqd to make " << m2 << " bouquets with " << k2 << " adjacent flowers are: " << minDays(bloomDay2, m2, k2);

    return 0;
}