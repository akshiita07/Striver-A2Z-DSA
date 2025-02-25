#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9; // modulo 109 + 7
int numOfSubarrays(vector<int> &arr)
{
    // return the number of subarrays with an odd sum
    int n = arr.size();
    int oddCount = 0;
    int evenCount = 1; // sum=0 is also even
    int prefixSum = 0;
    int ans = 0;
    for (auto it : arr)
    {
        prefixSum += it;
        // LOGIC: If the prefix_sum is odd, add even_count to the result && If the prefix_sum is even, we add odd_count to the result.
        // if even sum:
        if (prefixSum % 2 == 0)
        {
            ans = (ans + oddCount) % MOD;
            evenCount++;
        }
        else
        {
            ans = (ans + evenCount) % MOD;
            oddCount++;
        }
    }

    return ans % MOD;
}

int main()
{

    return 0;
}