#include <bits/stdc++.h>
using namespace std;

// function to check if palindrome or not:
bool isPalindrome(vector<int> digits)
{
    int n = digits.size();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (digits[i] != digits[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// function to convert a number to its base k representation:
vector<int> toBase(int number, int k)
{
    vector<int> digits;
    while (number > 0)
    {
        digits.push_back(number % k);
        number /= k;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

// function to check if a number is a k mirror number or not:
bool isKMirrorNumber(int number, int k)
{
    string numStr = to_string(number);
    // if reverse string & numStr are unequal then return F
    if (!equal(numStr.begin(), numStr.end(), numStr.rbegin()))
    {
        return false;
    }
    // else if palindrome then check if its k-base is palindrome or not:
    return isPalindrome(toBase(number, k));
}

long long kMirror(int k, int n)
{
    // k mirror no: + numb with no leading 0s that reads same in fwd & bwd with base 10 & base k
    // return the sum of the n smallest k-mirror numbers in base 10 ie decimals
    long long sum = 0;
    // generate palindrome numbers & check if they are k-mirror numbers:
    int i = 0;
    int number = 1;
    while (i < n)
    {
        if (isKMirrorNumber(number, k))
        {
            sum += number;
            i++;
        }
        number++;
    }
    return sum;
}

int main()
{
    int k = 3;
    int n = 7;
    cout << "\n sum of the n smallest k-mirror numbers= " << kMirror(k, n);
    return 0;
}