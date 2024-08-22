#include <bits/stdc++.h>
using namespace std;

// PRIME NUMBER HAS ONLY 2 DIVISORS: 1 & ITSELF

// TIME: O(n)->for loop
// SPACE: O(1)
bool brute_force(int num)
{
    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        // exactly 2 divisors
        return true;
    }
    else
    {
        return false;
    }
}

// optimized
// TIME: O(sqrt(n))
// SPACE: O(1)
bool isPrimeOrNot(int num)
{
    int count = 0;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            count++;
            if ((num / i) != i)
            {
                count++;
            }
        }
    }
    if (count == 2)
    {
        // exactly 2 divisors
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n1 = 1;
    cout << "\nBRUTE FORCE- Is " << n1 << " a prime number: " << brute_force(n1);
    cout << "\nIs " << n1 << " a prime number: " << isPrimeOrNot(n1);
    int n2 = 2;
    cout << "\nBRUTE FORCE- Is " << n2 << " a prime number: " << brute_force(n2);
    cout << "\nIs " << n2 << " a prime number: " << isPrimeOrNot(n2);
    int n3 = 10;
    cout << "\nBRUTE FORCE- Is " << n3 << " a prime number: " << brute_force(n3);
    cout << "\nIs " << n3 << " a prime number: " << isPrimeOrNot(n3);
    int n4 = 13;
    cout << "\nBRUTE FORCE- Is " << n4 << " a prime number: " << brute_force(n4);
    cout << "\nIs " << n4 << " a prime number: " << isPrimeOrNot(n4);

    return 0;
}