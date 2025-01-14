#include <bits/stdc++.h>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    // C:prefix common array where C[i] is equal to the count of numbers that are present AT or BEFORE the index i in both A and B
    unordered_map<int, int> hashMap;
    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        hashMap[A[i]]++;
        hashMap[B[i]]++;
        // now check if its count is 2 then add to ans
        if (hashMap[A[i]] == 2)
        {
            // occurred in both A & B:
            cnt++;
        }
        if (A[i] != B[i] && hashMap[B[i]] == 2)
        {
            // occurred in both A & B:
            cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main()
{
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    vector<int> ans = findThePrefixCommonArray(A, B);
    // 0,2,3,4
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}