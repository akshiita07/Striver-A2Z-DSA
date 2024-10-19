#include <bits/stdc++.h>
using namespace std;

char findKthBit(int n, int k)
{
    // binary string Sn
    //     S1 = "0"
    // Si = S(i-1) + "1" + reverse(invert(S(i-1)) for i > 1

    // Base case: If n = 1, the only bit is '0'
    if (n == 1)
    {
        return '0';
    }

    // Find the length of Sn
    int length = (1 << n) - 1; // 2^n - 1

    int mid = (length / 2) + 1; // Middle position

    if (k == mid)
    {
        // If k is the middle bit, it's always '1'
        return '1';
    }
    else if (k < mid)
    {
        // If k is in the first half, it's in Sn-1
        return findKthBit(n - 1, k);
    }
    else
    {
        // If k is in the second half, it's the mirrored and inverted bit from Sn-1
        int mirroredK = length - k + 1;
        char mirroredBit = findKthBit(n - 1, mirroredK);
        return mirroredBit == '0' ? '1' : '0'; // Invert the bit
    }
}

int main()
{
    int n = 4;
    int k = 11;
    cout << "\nThe kth bit in Sn is: " << findKthBit(n, k);

    return 0;
}