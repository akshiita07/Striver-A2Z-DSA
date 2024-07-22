#include <bits/stdc++.h>
using namespace std;

void findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    long long n=grid.size();
    vector<int> nums;
    for(auto row:grid){
        for(auto it:row){
            nums.push_back(it);
        }
    }
    int m=n*n;      //size of nums
    // repeat,missing
    vector<int> ans(2);
    long long x = 0; // repeat
    long long y = 0; // missing

    long long sumN = (m * (m + 1)) / 2;
    long long sum2N = (m * (m + 1) * (2 * m + 1)) / 6;
    long long sumArr = 0;
    long long sumSquare = 0;
    for (int i = 0; i < m; i++)
    {
        sumArr += nums[i];
        sumSquare += (long long)nums[i] * (long long)nums[i];
    }

    // equations:
    long long eq1 = sumArr - sumN;       // x-y=eq1
    long long eqAux = sumSquare - sum2N; // x2-y2=eqAux
    long long eq2 = eqAux / eq1;         // x+y=eq2

    x = (eq1 + eq2) / 2;
    y = eq2 - x;

    ans[0] = int(x);
    ans[1] = int(y);

    cout<<"Repeating & missing is: \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    // Output: [2,4]

    findMissingAndRepeatedValues(grid);

    return 0;
}