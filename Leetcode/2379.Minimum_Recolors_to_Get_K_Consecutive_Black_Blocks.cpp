#include <bits/stdc++.h>
using namespace std;

int minimumRecolors(string blocks, int k)
{
    int n = blocks.length(); // contains W:white & B:black
    // k- desired number of consecutive black block
    // Return the minimum number of operations to recolor a white to black block in 1operation to get atleast one series of k consecutive black boxes
    int whites = 0;
    for (int i = 0; i < k; i++)
    {
        if (blocks[i] == 'W')
        {
            whites++;
        }
    }
    int ans = whites;
    for (int i = k; i < n; i++)
    {
        if (blocks[i] == 'W')
        {
            whites++;
        }
        if (blocks[i - k] == 'W')
        {
            // remove leftmost
            whites--;
        }
        ans = min(ans, whites);
    }
    return ans;
}

int main()
{
    string blocks = "WBBWWBBWBW";
    int k = 7;
    cout << "\nMinimum number of operations= " << minimumRecolors(blocks, k);

    return 0;
}