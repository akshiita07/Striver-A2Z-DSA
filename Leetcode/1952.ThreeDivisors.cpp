#include <bits/stdc++.h>
using namespace std;

int count_divisors(int n)
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
    cout << "\nAll divisiors of number " << n << " are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return ans.size();
}

// TIME: O(sqrt(n))
// SPACE: O(n)->just for vector to calculate no of divisors 
bool isThree(int n)
{
    int noOfDivisors = 0;
    // find out how many divisors does each no has:
    if(count_divisors(n)==3){
        return true;
    }else{
        return false;
    }
}

int main()
{
    int n1=2;
    cout << "\nDoes "<<n1<<" have exactly 3 divisors: " << isThree(n1);
    int n2=4;
    cout << "\nDoes "<<n2<<" have exactly 3 divisors: " << isThree(n2);

    return 0;
}