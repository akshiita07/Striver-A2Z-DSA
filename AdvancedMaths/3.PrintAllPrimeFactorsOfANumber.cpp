#include <bits/stdc++.h>
using namespace std;

vector<int> findFactors(int num)
{
    vector<int> ans;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            ans.push_back(i);
            if ((num / i) != i)
            {
                ans.push_back((num/i));
            }
        }
    }
    return ans;
}
bool checkPrime(int num)
{
    int c = 0;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            c++;
            if ((num / i) != i)
            {
                c++;
            }
        }
    }
    if (c == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void AllPrimeFactors(int num)
{
    vector<int> ans;
    // find all factors
    vector<int> factors = findFactors(num);
    // check if factors r prime or not
    for (auto it : factors)
    {
        if (checkPrime(it) == true)
        {
            ans.push_back(it);
        }
    }
    cout << "\nThe prime factors of " << num << " are:";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    int n1 = 100;
    AllPrimeFactors(n1);
    cout << endl;
    int n2 = 35;
    AllPrimeFactors(n2);
    cout << endl;
    int n3 = 60;
    AllPrimeFactors(n3);

    return 0;
}