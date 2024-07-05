#include <bits/stdc++.h>
using namespace std;
// SOLVE USING RECURSION: WHEN FNC CALLS ITSELF UNITL A SPECIFIC CONDITION IE BASE CONDITION IS MET

// Q1. Print name n times:
// TIME COMPLEXITY: O(n) ->fnc calls itself for n times
// SPACE COMPLEXITY: O(n)-> using stack space
void printName(int count, int n)
{
    if (count > n) // base case
    {
        return;
    }
    cout << "Akshu" << endl;
    printName(count + 1, n);
}

// Q2. Print linearly from 1 to n
void printOnetoN(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << " ";
    printOnetoN(i + 1, n);
}

// Q3. Print linearly from n to 1
void printNtoOne(int n)
{
    if (n < 1)
    {
        return;
    }
    cout << n << " ";
    printNtoOne(n - 1);
}

// Q4. Print linearly from 1 to n using BACKTRACKING
void backtrackingOnetoN(int n)
{
    if (n < 1)
    {
        return;
    }
    backtrackingOnetoN(n - 1);
    cout << n << " "; // print call after recursion
}

// Q5. Print linearly from n to 1 using BACKTRACKING
void backtrackingNtoOne(int i, int n)
{
    if (i > n)
    {
        return;
    }
    backtrackingNtoOne(i + 1, n);
    cout << i << " ";
}

// Q6. Sum of first n natural nos: PARAMETRISED METHOD
int sumFirstN_param(int sum, int n)
{
    if (n < 1)
    {
        return sum;
    }
    else
    {
        sumFirstN_param(sum + n, n - 1);
    }
}

// Q6. Sum of first n natural nos: FUNCTION METHOD
int sumFirstN_fnc(int n)
{
    if (n < 1)
    {
        return 0;
    }
    else
    {
        return n + sumFirstN_fnc(n - 1);
    }
}

// Q7.Factorial of n
int fact(int n)
{
    if (n < 1)
    {
        // 0!=1
        return 1;
    }
    return n * fact(n - 1);
}

//  Q8. Reverse an array    USING FOR LOOP:
void revArr1()
{
    int arr[] = {1, 2, 3, 4, 2};
    vector<int> v;
    for (int i = 4; i >= 0; i--)
    {
        v.emplace_back(arr[i]);
    }

    cout << "Reversed array is: \n";
    for (auto x : v)
    {
        cout << x << " ";
    }
}

//  Q8. Reverse an array    USING SWAP & FOR LOOP
void revArr2()
{
    int arr[] = {1, 2, 3, 4, 2};
    int i = 0;
    int j = 4;
    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    cout << "Reversed array is: \n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}

//  Q8. Reverse an array    USING recursion & 2 pointers:
int *revArrRecursion2ptr(int i, int j, int arr[])
{
    if (i > j)
    {
        // when i crosses j then return arrayb
        return arr;
    }
    else
    {
        swap(arr[i], arr[j]);
        revArrRecursion2ptr(i + 1, j - 1, arr);
    }
}

//  Q9. Reverse an array    USING recursion & ONLY 1 pointer:
int *revArrRecursion1ptr(int i, int arr[], int n)
{
    if (i >= (n / 2))
    {
        // when i crosses j then return arrayb
        return arr;
    }
    else
    {
        // n=4 ie length of arr
        swap(arr[i], arr[n - i - 1]);
        revArrRecursion1ptr(i + 1, arr, n);
    }
}

// Q10. Check if string is palindrome or not?
bool isPalindrome(string str)
{
    cout << "Length of string is: " << str.length() << endl;
    int n = str.length();
    int i = 0;

    while (i < n - i - 1)
    {
        if (str[i] == str[n - i - 1])
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

// Q10. Check if string is palindrome or not? USE RECURSION:
bool isPalindromeRec(string str, int n, int i)
{
    if (i >= n - i - 1)
    {
        return true;
    }
    else
    {
        if (str[i] == str[n - i - 1])
        {
            return isPalindromeRec(str, n, i + 1);
        }
        else
        {
            return false;
        }
    }
}

bool isPalindromeLeetcode(string s)
{
    cout << "Length string is: " << s.length();//30
    // remove all spaces & commas & stuff
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' '||s[i] == ','||s[i] == ':')
        {
            s.erase(i,1);
            i--;
        }
    }
    cout << "After removal string is: " << s<<endl;

    // remove all cases->all small
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }

    cout << "After lowercase string is: " << s<<endl;
    int n = s.length();
    int i = 0;
    while (i < n - i - 1)
    {
        if (s[i] == s[n - i - 1])
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return true ;
}

// MULTIPLE RECURSION CALLS= OCCURS 1 BY 1

// Q11. Print fibonacci series
int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
//for n=4-> 9recursion calls
// exponential time O(2^n)


int main()
{
    // int count = 1;
    // printName(count, 5);

    // printOnetoN(1,10);

    // printNtoOne(10);

    // backtrackingOnetoN(10);

    // backtrackingNtoOne(1,10);

    // cout<<"Sum of first 5 nat nos parametrised : "<<sumFirstN_param(0,5)<<endl;

    // cout<<"Sum of first 5 nat nos fnct : "<<sumFirstN_fnc(5)<<endl;

    // cout<<"Factorial of 4 is: "<<fact(4)<<endl;

    // revArr1();
    // revArr2();

    int arr[] = {1, 2, 3, 4, 5};
    // revArrRecursion2ptr(0, 4,arr);
    // revArrRecursion1ptr(0,arr, 5);
    // cout << "\nReversed array is: \n";
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // cout << "Is string madam a palindrome? " << isPalindrome("madam") << endl;
    // cout << "Is string man a palindrome? " << isPalindrome("man") << endl;

    // string str = "civic";
    // int n = str.length();
    // cout << "Is string civic a rec palindrome? " << isPalindromeRec(str, n, 0) << endl;
    // cout << "Is string man a rec palindrome? " << isPalindromeRec("man", 3, 0) << endl;

    // string s = "A man, a plan, a canal: Panama";
    // cout << "Is string palindrome? " << isPalindromeLeetcode(s) << endl;

    cout<<"Fibonacci 4 is: "<<fib(4)<<endl;
    cout<<"Fibonacci 5 is: "<<fib(5)<<endl;

    return 0;
}