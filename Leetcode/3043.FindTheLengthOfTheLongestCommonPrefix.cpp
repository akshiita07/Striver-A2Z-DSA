#include <bits/stdc++.h>
using namespace std;
//      Find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

// Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.

int findPrefixLength(int num1, int num2)
{
    // convert both numbers to string
    string strNum1 = to_string(num1);
    string strNum2 = to_string(num2);
    int commonPref = 0;

    // go upto min len
    for (int i = 0; i < min(strNum1.length(), strNum2.length()); i++)
    {
        if (strNum1[i] == strNum2[i])
        {
            commonPref++;
        }
        else
        {
            // first uncommon found so stop
            break;
        }
    }
    return commonPref;
}
int brute_force(vector<int> &arr1, vector<int> &arr2)
{
    // make pairs of arr1 & arr2 elements n keep track of longest prefix matching
    // take max out of them
    int n1 = arr1.size();
    int n2 = arr2.size();
    int maxLen = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            // for pair of int i & j find max common prefix
            int commonPrefix = findPrefixLength(arr1[i], arr2[j]);
            maxLen = max(maxLen, commonPrefix);
        }
    }
    return maxLen;
}
// optimal
int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    unordered_set<int> prefixes;

    // Insert all prefixes of all numbers in nums1 into the set
    // A prefix here is obtained by repeatedly dividing the number by 10
    for (auto it : arr1)
    {
        for (; it; it /= 10)
        {
            // get single digit numbers
            prefixes.insert(it);
        }
    }

    int maxLen = 0;

    // Iterating through each number in nums2
    for (auto it : arr2)
    {
        // Break down the number into prefixes and check against our set
        for (; it; it /= 10)
        {
            // If the current prefix is in the set, it's a common prefix
            if (prefixes.count(it))
            {
                // Logarithm base 10 of num gives us the number of digits -1
                maxLen =max(maxLen, (int)log10(it) + 1);
                // once the longest prefix for current num is found, no need
                // to look for shorter ones
                break;
            }
        }
    }
    // Return the length of the longest common prefix
    return maxLen;
}

int main()
{
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};
    cout << "\nThe length of longest common prefix is: " << brute_force(arr1, arr2);
    cout << "\nOptimal: The length of longest common prefix is: " << longestCommonPrefix(arr1, arr2);

    return 0;
}