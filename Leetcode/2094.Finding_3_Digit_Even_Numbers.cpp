#include <bits/stdc++.h>
using namespace std;

// Brute force: Time: O()
vector<int> brute_force(vector<int> &digits)
{
    // from all given digits, form 3 digit unqiue even numbers (with NO leading zeros)
    vector<int> ans;
    // for all even digit numbers from 100 to 998: check if it can be forme using given digits
    unordered_map<int, int> hashMap; // map each digit to its count of occurrence
    int n = digits.size();
    for (int i = 0; i < n; i++)
    {
        hashMap[digits[i]]++;
    }
    // check if number can be formed using given digits:
    for (int i = 100; i <= 998; i += 2)
    {
        // create a temporary hash map so that it does not affect the original hash map:
        unordered_map<int, int> tempHashMap = hashMap;
        bool canForm = true;
        while (i > 0)
        {
            // extract digits:
            int digit = i % 10;
            // check if digit is present in hashMap:
            if (tempHashMap[digit] > 0)
            {
                // present so dec its count in map:
                tempHashMap[digit]--;
            }
            else
            {
                canForm = false;
                break;
            }
            i = i / 10;
        }
        if (canForm == true)
        {
            ans.push_back(i); // this digit is possible
        }
    }
    // return sorted array:
    sort(ans.begin(), ans.end());
    return ans;
}

// Better approach: O(n^3)
vector<int> better_approach(vector<int> &digits)
{
    // from all given digits, form 3 digit unqiue even numbers (with NO leading zeros)
    // take set to avoid duplicates:
    set<int> ans;
    unordered_map<int, int> hashMap; // map each digit to its count of occurrence
    int n = digits.size();
    for (int i = 0; i < n; i++)
    {
        hashMap[digits[i]]++;
    }
    // generate all 3 digit permuttations of given digits:
    for (int i = 0; i < n; i++)
    {
        if (digits[i] == 0)
        {
            continue; // skip leading zeros:
        }
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            for (int k = 0; k < n; k++)
            {
                if (i == k || j == k)
                {
                    continue; // skip same digits:
                }
                int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                if (number % 2 != 0)
                {
                    continue; // skip odd numbers:
                }
                unordered_map<int, int> tempHashMap;
                tempHashMap[digits[i]]++;
                tempHashMap[digits[j]]++;
                tempHashMap[digits[k]]++;
                bool canForm = true;
                for (auto [digit, cnt] : tempHashMap)
                {
                    // count exceeds
                    if (cnt > hashMap[digit])
                    {
                        canForm = false; // not possible to form this number:
                        break;
                    }
                }
                if (canForm)
                {
                    ans.insert(number); // this digit is possible
                }
            }
        }
    }
    // filter out all even numbers:
    return vector<int>(ans.begin(), ans.end());
}

// Optimized approach: O(998-100/2)=O(898/2)=O(449)
vector<int> findEvenNumbers(vector<int> &digits)
{
    // from all given digits, form 3 digit unqiue even numbers (with NO leading zeros)
    vector<int> ans;
    unordered_map<int, int> hashMap; // map each digit to its count of occurrence
    int n = digits.size();
    for (int i = 0; i < n; i++)
    {
        hashMap[digits[i]]++;
    }
    for (int i = 100; i <= 998; i += 2)
    {
        int d1 = i / 100;
        int d2 = (i / 10) % 10;
        int d3 = (i) % 10;
        // create a temporary hash map so that it does not affect the original hash map:
        unordered_map<int, int> tempHashMap;
        tempHashMap[d1]++;
        tempHashMap[d2]++;
        tempHashMap[d3]++;
        bool canForm = true;
        for (int i = 0; i < 10; i++)
        {
            if (tempHashMap[i] > hashMap[i])
            {
                canForm = false; // not possible to form this number:
                break;
            }
        }
        if (canForm == true)
        {
            ans.push_back(i); // this digit is possible
        }
    }
    // filter out all even numbers:
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> digits = {2, 1, 3, 0};
    // Output: [102,120,130,132,210,230,302,310,312,320]
    vector<int> ans1 = brute_force(digits);
    cout << "Array using brute_force: \n";
    for (auto it : ans1)
    {
        cout << it << " ";
    }
    vector<int> ans2 = better_approach(digits);
    cout << "Array using better approach: \n";
    for (auto it : ans2)
    {
        cout << it << " ";
    }
    vector<int> ans3 = findEvenNumbers(digits);
    cout << "Array using Optimized approach: \n";
    for (auto it : ans3)
    {
        cout << it << " ";
    }

    return 0;
}