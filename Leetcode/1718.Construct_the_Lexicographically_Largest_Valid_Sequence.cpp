#include <bits/stdc++.h>
using namespace std;

// pass ans by reference:
bool backtrack(vector<int> &ans, vector<bool> &used, int n, int index) // start by placing at index=0 initially then move to next index if not feasible
{
    // base case if size completed:
    if (ans.size() == index)
    {
        return true;
    }

    // if position is filled ie if value is not 0 then go to next index:
    if (ans[index] != 0)
    {
        // return so that if position is filled then we conitnue searching for next indices:
        return backtrack(ans, used, n, index + 1);
    }

    // start by placing largest numbers first to create lexicographically largest:
    // loop from n to 1:
    for (int i = n; i >= 1; i--)
    {
        // number 1 must be placed only once:
        if (i == 1)
        {
            if (!used[i])
            {
                ans[index] = 1;
                used[i] = true;
                // continue filling sequence & return true is possible else this is not position for 1 so remove it:
                if (backtrack(ans, used, n, index + 1))
                {
                    return true;
                }
                ans[index] = 0; // if false returned
                used[i] = false;
            }
        }
        else
        {
            int nextIndex = index + i;
            // if within bounds & currently not filled by nextIndex & also not earlier used:
            if (nextIndex < ans.size() && !used[i] && ans[nextIndex] == 0)
            {
                // insert numbers:
                ans[index] = i;
                ans[nextIndex] = i;
                used[i] = true;
                // check if backtrack possible then return true else reset indices to 0:
                if (backtrack(ans, used, n, index + 1))
                {
                    return true;
                }
                // reset indices:
                ans[index] = 0;
                ans[nextIndex] = 0;
                used[i] = false;
            }
        }
    }
    return false;
}

vector<int> constructDistancedSequence(int n)
{
    // add 1 in sequence
    // each number from 2 to n has to be inserted 2 times..also the dist(diff of indices) bw 2 occurences of i must be i
    // return lexicographically largest sequence
    // so size of array: 1+2(n-1)=2n-2+1=2n-1
    int size = 2 * n - 1;
    // create ans vector initialised with 0s:
    vector<int> ans(size, 0);
    // create a vector for already used numbers:
    vector<bool> used(n + 1, false);
    backtrack(ans, used, n, 0);
    return ans;
}

int main()
{
    int n = 3;
    cout << "\nAns: ";
    vector<int> ans = constructDistancedSequence(n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}