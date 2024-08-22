#include <bits/stdc++.h>
using namespace std;

// TIME: O(n)->for loop
// SPACE: O(n)->vector to return answer!
void brute_force(int n)
{
    vector<int> ans;
    // check all divisors from 1 to number itself
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
        }
    }
    cout << "\nAll divisiors of number " << n << " are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

//
// TIME: O(sqrt(n))
// SPACE: O(n)->to return ans as vector
void print_divisors(int n)
{
    vector<int> ans;
    // check all divisors from 1 to number itself
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            // for second divisor: no/i:
            if ((n / i) != i)
            {
                // do not add same divisor twice
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end()); // sort array also
    cout << "\nAll divisiors of number " << n << " are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    int n = 20;
    // brute_force(n);
    print_divisors(n);

    return 0;
}