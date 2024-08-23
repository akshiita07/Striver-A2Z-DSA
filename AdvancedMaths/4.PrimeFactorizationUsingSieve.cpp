#include <bits/stdc++.h>
using namespace std;

// TIME: O(sqrt(n))
// SPACE: O(n)->to return ans
void brute_force(int n)
{
    vector<int> ans;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // ie divisble so keep on dividing
            while (n % i == 0)
            {
                ans.push_back(i);
                n = n / i;
            }
        }
    }
    if (n != 1)
    {
        ans.push_back(n);
    }
    cout << "\nThe prime factors of " << n << " are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

// SEIVE USED IS: SPF- smallest prime factor
vector<int> sieve(int n)
{
    vector<int> spf(n + 1);
    // from 2 to n store indices a values
    for (int i = 2; i <= n; i++)
    {
        spf[i] = i;
    }
    // now loop till sqrt(n)
    for (int i = 2; i <= sqrt(n); i++)
    {
        // check if it is prime
        if (spf[i] == i)
        {
            // is prime:
            // update factors:
            for (int j = i * i; j <= n; j = j + i)
            {
                // check if factors r not previously updated
                if (spf[j] == j)
                {
                    // now update it
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

void findPrimeFactors(int n)
{
    vector<int> spf=sieve(n);
    vector<int> ans;
    while (n != 1)
    {
        ans.push_back(spf[n]);
        n = n / spf[n];
    }
    // return ans;
    cout << "\nThe prime factors of " << n << " are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    int n = 60;
    // brute_force(n);
    findPrimeFactors(n);

    return 0;
}