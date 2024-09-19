#include <bits/stdc++.h>
using namespace std;

// to use this as memeber function add static bool
bool myCustomComparator(string &a, string &b)
{
    // concate any 2 string numbers at a time & check whose int value is greater
    if (a + b > b + a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string largestNumber(vector<int> &nums)
{
    //    arrange nums such that they form the largest number and return it

    // convert all integer numbers to strings:
    vector<string> stringNums;
    for (auto it : nums)
    {
        stringNums.push_back(to_string(it));
    }

    // sort strings based on our custom comparator:
    sort(stringNums.begin(), stringNums.end(), myCustomComparator);

    // if string contains only 0,0 then return 0:
    if (stringNums[0] == "0")
    {
        // return only 1 single zero
        return "0";
    }

    // concatenate result into a string to return:
    string ans = "";
    for (auto it : stringNums)
    {
        ans += it;
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    // first digit kiska max hai-> 9
    // sec digit kiska max hai->5
    // third digit kiska max hai->3-->check aage digits hai->34
    // then 3  (IF NOTHING THEN TAKE FIRST IF ZERO THEN TAKE AFTERWARDS)
    // then 30
    // 9 5 34 3 30
    cout << "\nThe largest number formed is: " << largestNumber(nums);

    return 0;
}