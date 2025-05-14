#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int alphabets = 26;

// MATRIX MULTIPLICATION FUNCTION:
vector<vector<long long>> multiplyMatrices(vector<vector<long long>> &A, vector<vector<long long>> &B)
{
    vector<vector<long long>> ans(alphabets, vector<long long>(alphabets, 0));
    for (int i = 0; i < alphabets; i++)
    {
        for (int j = 0; j < alphabets; j++)
        {
            for (int k = 0; k < alphabets; k++)
            {
                ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return ans;
}

// MATRIX EXPONENTIAL FUNCTION:
vector<vector<long long>> matrixExponential(vector<vector<long long>> base, long long exp)
{
    vector<vector<long long>> ans(alphabets, vector<long long>(alphabets, 0));
    for (int i = 0; i < alphabets; i++)
    {
        ans[i][i] = 1;
    }
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            ans = multiplyMatrices(ans, base);
        }
        base = multiplyMatrices(base, base);
        exp /= 2;
    }
    return ans;
}

// Time: O(26^t × log t)
int lengthAfterTransformations(string s, int t, vector<int> &nums)
{
    // array nums of size 26
    // t denotes no of transformations to be performed
    // convert each s[i] to nums[s[i]-'a] and loop around z ie next to z->a,b,c...
    // MATRIX MULTIPLICATION PROBLEM: instead of ifnding string we will look for frequency of elements
    vector<vector<long long>> matrix(alphabets, vector<long long>(alphabets, 0));
    for (int i = 0; i < alphabets; i++)
    {
        int count = nums[i];
        for (int j = 1; j <= count; j++)
        {
            int tranf = (i + j) % alphabets;
            matrix[tranf][i] = (matrix[tranf][i] + 1) % mod;
        }
    }
    vector<long long> freq(alphabets, 0);
    for (auto it : s)
    {
        freq[it - 'a']++;
    }
    // apply tansformation t times:
    vector<vector<long long>> ans = matrixExponential(matrix, t);
    vector<long long> finalFreq(alphabets, 0);
    for (int i = 0; i < alphabets; i++)
    {
        for (int j = 0; j < alphabets; j++)
        {
            finalFreq[i] = (finalFreq[i] + (ans[i][j] * freq[j])) % mod;
        }
    }
    long long total = 0;
    for (int i = 0; i < alphabets; i++)
    {
        total = (total + finalFreq[i]) % mod;
    }
    return total;
}

int main()
{
    string s = "azbk";
    int t = 1;
    vector<int> nums = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    cout << "\nLength of string after transformations: " << lengthAfterTransformations(s, t, nums);

    return 0;
}