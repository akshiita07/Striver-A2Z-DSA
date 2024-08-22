#include <bits/stdc++.h>
using namespace std;

vector<int> giveDivisors_ExcludingNumberItself(int num)
{
    vector<int> ans;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            ans.push_back(i);
            if ((num / i) != num && (num / i) != i)
            {
                ans.push_back(num / i);
            }
        }
    }
    return ans;
}

bool checkPerfectNumber(int num)
{
    if (num == 1)
    {
        return false;
    }
    // is sum of all divisors exclusing number itself==num then T
    vector<int> divisors = giveDivisors_ExcludingNumberItself(num);
    // sum all these & check if sum==num?
    int sum = 0;
    for (auto it : divisors)
    {
        sum += it;
    }
    if (sum == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n1 = 28;
    cout << "\nIs " << n1 << " a perfect number: " << checkPerfectNumber(n1);
    int n2 = 7;
    cout << "\nIs " << n2 << " a perfect number: " << checkPerfectNumber(n2);

    return 0;
}