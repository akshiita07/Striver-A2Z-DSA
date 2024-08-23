#include <bits/stdc++.h>
using namespace std;

vector<int> getSeive(int left, int right)
{
    vector<int> ans;
    vector<int> primeArr(right + 1);
    for (int i = 2; i <= right; i++)
    {
        primeArr[i] = 1;
    }
    for (int i = 2; i <= sqrt(right); i++)
    {
        if (primeArr[i] == 1)
        {
            // is prime so remove multiples:
            for (int j = i * i; j <= right; j = j + i)
            {
                primeArr[j] = 0;
            }
        }
    }

    for (int i = left; i <= right; i++)
    {
        if (primeArr[i] == 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

void closestPrimes(int left, int right)
{
    vector<int> ans;

    // check all prime nos between left & right
    vector<int> primeFactors = getSeive(left, right);
    cout << "\nThe prime numbers between " << left << " & right are= ";
    for (auto it : primeFactors)
    {
        cout << it << " ";
    }

    // if only 1/none primeFactors exists then return [-1,-1]
    if (primeFactors.size() <= 1)
    {
        ans = {-1, -1};
    }
    else if (primeFactors.size() > 1)
    {
        // find min range in these primeFactors:  11 13 17 19
        int minDiff = INT_MAX;
        for (int i = 0; i < primeFactors.size() - 1; i++)
        {
            int diff = primeFactors[i + 1] - primeFactors[i];
            if (diff < minDiff)
            {
                minDiff = diff;
                ans = {primeFactors[i], primeFactors[i + 1]};
            }
        }
    }

    cout << "\nThe prime numbers between " << left << " & right with min range= ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    int left = 10;
    int right = 19;
    closestPrimes(left, right);

    return 0;
}