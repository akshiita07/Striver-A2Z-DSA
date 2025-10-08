#include <bits/stdc++.h>
using namespace std;

vector<int> brute_force(vector<int> &spells, vector<int> &potions, long long success)
{
    int n = spells.size();
    int m = potions.size();
    // spells[i]: strength of the ith spell
    //  potions[j]: strength of the jth potion
    // {spell,potion} pair is successful if : spell[i]*potion[j]>=success
    vector<int> pairs(n, 0);
    // where pairs[i]= no of potions that can be successfully paired with ith spell
    sort(potions.begin(), potions.end());
    // check for each spell:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (1LL * spells[i] * potions[j] >= success)
            {
                pairs[i] = m - j; // choose least only then others would be there by default
                break;
            }
            else
            {
                pairs[i] = 0;
            }
        }
    }
    return pairs;
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    int n = spells.size();
    int m = potions.size();
    // spells[i]: strength of the ith spell
    //  potions[j]: strength of the jth potion
    // {spell,potion} pair is successful if : spell[i]*potion[j]>=success
    vector<int> pairs(n, 0);
    // where pairs[i]= no of potions that can be successfully paired with ith spell
    sort(potions.begin(), potions.end());
    // check for each spell:
    for (int i = 0; i < n; i++)
    {
        // check which min potion can be paired with ith spell using binary search
        int l = 0;
        int r = m - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (1LL * spells[i] * potions[mid] >= success)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        pairs[i] = m - l;
    }
    return pairs;
}

int main()
{

    return 0;
}