#include <bits/stdc++.h>
using namespace std;

// TIME: O(n)->for loop + O(k)->to pop while loop + O(n)->add from stack to string + O(n)->reversing number + O(n)->removing 0s from end == O(3n+k)
// SPACE: O(n)->for stack   + O(n)->to return string as answer == O(2n)
string removeKdigits(string num, int k)
{
    stack<char> st; // stores characters
    int n = num.length();

    if (k == n)
    {
        // all digits will be removed
        return "0";
    }

    // traverse thru string
    for (int i = 0; i < n; i++)
    {
        while (st.empty() == false && k > 0 && (st.top() - '0') > (num[i]) - '0')
        {
            // bigger then pop & reduce k
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    // check if k is still left then remove elements from RIGHT
    while (k > 0)
    {
        st.pop(); // remove top elements from stack!
        k--;
    }

    // add elements from stack into string
    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    // check for zeroes at end:
    while (!ans.empty() && ans.back() == '0')
    {
        ans.pop_back();
    }

    // reverse string:
    reverse(ans.begin(), ans.end());
// check if still ans is empty eg:"10" then all elem removed so return "0"
    if(ans.empty()){
            return "0";
        }

    return ans;
}

int main()
{
    string num = "1432219";
    int k = 3;
    cout << "\nThe SMALLEST possible number when " << k << " digits r removed: " << removeKdigits(num, k);

    return 0;
}