// 0 1 1 2 3 5 8 13 _ _ _
// recurrence relation: f(n)=f(n-1)+f(n-2)
#include <bits/stdc++.h>
using namespace std;

int fib_recurrsion(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib_recurrsion(n - 1) + fib_recurrsion(n - 2);
}

// overlapping sub-problems: solving same sub-problems again & again

// MEMOIZATION: STORE VALUES OF SUB-PROBLEMS in some map/table
// TOP-DOWN APPROACH
// TIME: O(n) linear time
// SPACE: O(n)recursion stack space + O(n) dp array
int fib_memoization(int n)
{
    vector<int> dp(n + 1, -1); // initilize dp array with -1
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        // already solved sub-problem
        return dp[n];
    }
    dp[n] = fib_memoization(n - 1) + fib_memoization(n - 2);
    return dp[n];
}

// TABULATION: BOTTOM-UP APPROACH: base case to reqd ans
// TIME: O(n)
// SPACE: O(n) : no recursive stack space only dp array
int fib_tabulation(int n)
{
    vector<int> dp(n + 1, -1); // initilize dp array with -1
    // base cases:
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) // start from 2 to number u want
    {
        dp[i] = fib_tabulation(i - 1) + fib_tabulation(i - 2);
    }
    return dp[n];
}

// OPTIMIZED TABULATION: WITH SPACE OPTIMIZATION
// TIME: O(n)
// SPACE: O(1)
int fib_tabulation_with_space_optimization(int n)
{
    // base cases:
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++) // start from 2 to number u want
    {
        int next = prev1 + prev2;
        prev2 = prev1;
        prev1 = next;
    }
    return prev1;
}

int main()
{
    cout << "\nFib of 4= " << fib_recurrsion(4);
    cout << "\nFib of 5= " << fib_memoization(5);
    cout << "\nFib of 6= " << fib_tabulation(6);
    cout << "\nFib of 7= " << fib_tabulation_with_space_optimization(7);

    return 0;
}