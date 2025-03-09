#include <bits/stdc++.h>
using namespace std;

int numberOfAlternatingGroups(vector<int> &colors, int k)
{
    // colors[i] == 0: red & colors[i] == 1: blue
    // check from each index if alternating colors present then count++
    int n = colors.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool isAlternating = true;
        // check kth length window:
        for (int j = 1; j < k; j++)
        {
            // If two adjacent colors are the same, it breaks the loop because the sequence is not alternating
            if (colors[(i + j) % n] == colors[(i + j - 1) % n])
            {
                isAlternating = false;
                break;
            }
        }
        if (isAlternating)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<int> colors = {0, 1, 0, 1, 0};
    int k = 2;
    cout << "\nAlt colors= " << numberOfAlternatingGroups(colors, k) << endl;
    return 0;
}