#include <bits/stdc++.h>
using namespace std;

// 3 types of dominos: left ,right, vertical
// if vertical dominos is pushed from both sides it will remain same vertical
//  dominoes[i] = 'L': pushed to the left
// dominoes[i] = 'R': pushed to the right
// dominoes[i] = '.' :not been pushed.
// Return a string representing the final state.

// Time: O(n^2)
string brute_force(string dominoes)
{
    int n = dominoes.length();
    // R will push next . to R
    // L will push previous . to L
    // R->.<-L then remain .
    string ans = dominoes;
    bool changed = true;
    while (changed)
    {
        changed = false;
        string newStr = ans;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == '.')
            {
                // define conditions for both types of push:
                // L pushed to . from <---
                bool leftPush = (i < n - 1 && ans[i + 1] == 'L');
                // R pushed to . from -->
                bool rightPush = (i > 0 && ans[i - 1] == 'R');
                // if pushed from both sides then it will remain .
                if (leftPush && rightPush)
                {
                    continue;
                }
                else if (rightPush)
                {
                    newStr[i] = 'R';
                    changed = true;
                }
                else if (leftPush)
                {
                    newStr[i] = 'L';
                    changed = true;
                }
            }
        }
        ans = newStr;
    }
    return ans;
}

// time : O(n)
string pushDominoes(string dominoes)
{
    int n = dominoes.length();
    // try simulating foces:
    vector<int> force(n, 0);
    int f = 0;
    // left to right: R applies force towards right but L will reset it to 0
    for (int i = 0; i < n; i++)
    {
        if (dominoes[i] == 'R')
        {
            f = n;
        }
        else if (dominoes[i] == 'L')
        {
            f = 0;
        }
        else
        {
            f = max(f - 1, 0);
        }
        force[i] += f;
    }
    // restart:
    f = 0;
    // right to left: L applies force towards left but R will reset it to 0: provide -ve forces to L to distinguish R and l
    for (int i = n - 1; i >= 0; i--)
    {
        if (dominoes[i] == 'L')
        {
            f = n;
        }
        else if (dominoes[i] == 'R')
        {
            f = 0;
        }
        else
        {
            f = max(f - 1, 0);
        }
        force[i] -= f;
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (force[i] > 0)
        {
            ans += 'R';
        }
        else if (force[i] < 0)
        {
            ans += 'L';
        }
        else if (force[i] == 0)
        {
            ans += '.';
        }
    }
    return ans;
}

int main()
{
    string dominoes = ".L.R...LR..L..";
    cout << "\nbrute_force string representing the final state= " << brute_force(dominoes);
    cout << "\nstring representing the final state= " << pushDominoes(dominoes);
    // Output: "LL.RR.LLRRLL.."
    return 0;
}