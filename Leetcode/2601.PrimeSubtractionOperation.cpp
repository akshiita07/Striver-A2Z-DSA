#include <bits/stdc++.h>
using namespace std;

// bool isPrime(int n)
// {
//     if (n <= 1)
//     {
//         return false;
//     }
//     if (n <= 3)
//     {
//         return true; // ie 2
//     }
//     if (n % 2 == 0 || n % 3 == 0)
//     {
//         return false;
//     }
//     for (int i = 5; i <= sqrt(n); i += 6)
//     {
//         if (n % i == 0 || n % (i + 2) == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int primeNumLessThanX(int x)
// {
//     for (int i = x - 1; i > 1; i--)
//     {
//         if (isPrime(i))
//         {
//             // is prime so return
//             return i;
//         }
//     }
//     return -1;
// }

// Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i]
//  make nums a strictly increasing array:true else false
int getMaxElement(vector<int> &nums)
{
    int max = -1;
    for (int num : nums)
    {
        if (num > max)
        {
            max = num;
        }
    }
    return max;
}
bool primeSubOperation(vector<int> &nums)
{
    int maxElement = getMaxElement(nums);
    // Create Sieve of Eratosthenes array to identify prime numbers
    vector<bool> sieve(maxElement + 1, true);
    sieve[1] = false;
    for (int i = 2; i <= sqrt(maxElement + 1); i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= maxElement; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    // Check if array can be made strictly increasing by subtracting prime numbers
    int currValue = 1;
    int i = 0;
    while (i < nums.size())
    {
        int difference = nums[i] - currValue;
        // Return false if current number is already smaller than required value
        if (difference < 0)
        {
            return false;
        }
        // Move to next number if difference is prime or zero
        if (sieve[difference] == true || difference == 0)
        {
            i++;
            currValue++;
        }
        else
        {
            currValue++;
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {4, 9, 6, 10};
    cout << "\nIs array stric inc after operation: " << primeSubOperation(nums);

    return 0;
}