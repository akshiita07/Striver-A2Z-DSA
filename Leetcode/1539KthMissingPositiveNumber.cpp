#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: TIME:O(k)
int brute_force(vector<int> &arr, int k)
{
    int missingNo;
    int n = arr.size();
    vector<int> missingArr;
    int i = 0;
    int count = 1;

    // k can go upto 1000
    while (missingArr.size() < k)
    {
        if (arr[i] == count)
        {
            // found so go on next element
            count++;
            i++;
        }
        else
        {
            // add in missing
            missingArr.push_back(count);
            count++;
        }
    }
    // find kth missing
    missingNo = missingArr[k - 1]; // 1 base indexing

    return missingNo;
}

// BETTER: TIME:O(n)
int better(vector<int> &arr, int k)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            // arr[i]>k
            break;
        }
    }
    return k;
}

// Binary SEARCH: TIME:O(log2n)
int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int kNo;
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missingNos = arr[mid] - (mid + 1);

        if (missingNos < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // high points to element
    kNo = low + k;

    return kNo;
}

int main()
{

    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "\nBRUTE FORCE: The " << k << "th missing number from arr is= " << brute_force(arr, k);
    cout << "\nBETTER: The " << k << "th missing number from arr is= " << better(arr, k);
    cout << "\nThe " << k << "th missing number from arr is= " << findKthPositive(arr, k);

    return 0;
}