#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string> &bank)
{
    // m*n
    int m = bank.size();
    int n = bank[0].size();
    // bank[i] : ith row consisting of '0'->cell is empty and '1'->has a security device
    // 1 laser beam bw 2 security devices if both on diff rows r1,r2 and r1 < r2 and for rows in between r1 and r2 there are no security devides
    // Return the total number of laser beams in the bank
    vector<int> row;
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {

            if (bank[i][j] == '1')
            {
                cnt++;
            }
        }
        if (cnt > 0)
        {
            row.push_back(cnt);
        }
    }
    // now count beams:
    int ans = 0;
    for (int i = 1; i < row.size(); i++)
    {
        ans += row[i - 1] * row[i];
    }
    return ans;
}

int main()
{

    return 0;
}