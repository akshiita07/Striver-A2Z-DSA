#include <bits/stdc++.h>
using namespace std;

vector<int> lexicalOrder(int n)
{
    vector<int> ans;
    int start = 1;
    // loop for n times:
    for (int i = 0; i < n; i++)
    {
        // push current no:
        ans.push_back(start);
        if (start * 10 <= n)
        {
            // the next lexicographic no is obtained on *10
            start = start * 10;
        }
        else
        {
            // if we exceeded n then backtrack:
            if (start >= n)
            {
                start = start / 10;
            }
            start++;
            // remove trailing zeroes
            // example, after 19, the next number lexicographically is 2, but incrementing 19 would give 20. So, we divide by 10 to move back up, resulting in 2
            while (start % 10 == 0){
                    start /= 10;
                }
        }
    }
    return ans;
}

int main()
{
    int n = 13;
    vector<int> ans = lexicalOrder(n);
    cout << "\nThe lexicographic ordering upto " << n << " is: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}