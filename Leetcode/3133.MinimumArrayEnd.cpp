#include <bits/stdc++.h>
using namespace std;

long long minEnd(int n, int x)
{
    // construct array of size n
    // at each index: nums[i + 1]>nums[i]
    // result of the bitwise AND operation between all elements of nums is x
    // Return the minimum possible value of nums[n - 1]

    n--; // Adjust n to work with zero-based indexing
    long long ans = x;

    // Iterate over each bit position from 0 to 30 (sufficient for 32-bit integers)
    for (int i = 0; i < 31; i++)
    {
        // Check if the i-th bit in x is 0
        if (((x >> i) & 1) == 0)
        {
            // Set the i-th bit of ans if the last bit of n is 1
            ans += (n & 1) << i;
            // Right shift n to process the next bit in the next loop iteration
            n >>= 1;
        }
    }

    // Set any remaining bits in n to the higher positions starting from bit 31
    ans += (1LL * n) << 31;

    return ans;
}

int main()
{
    int n = 3;
    int x = 4;
    cout << "\nMin value for last index of array is: " << minEnd(n, x);

    return 0;
}