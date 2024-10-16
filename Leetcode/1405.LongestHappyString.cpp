#include <bits/stdc++.h>
using namespace std;

string longestDiverseString(int a, int b, int c)
{
    // s must contain only 'a','b','c'
    // s must NOT contain  "aaa", "bbb", or "ccc" as a substring
    //     s contains at most a occurrences of the letter 'a'.
    // s contains at most b occurrences of the letter 'b'.
    // s contains at most c occurrences of the letter 'c'
    // return the longest possible happy string

    // Max heap to store characters and their remaining counts
    priority_queue<pair<int, char>> pq;

    // Add characters with their counts to the priority queue
    if (a > 0)
        pq.push({a, 'a'});
    if (b > 0)
        pq.push({b, 'b'});
    if (c > 0)
        pq.push({c, 'c'});

    string ans = "";

    // Continue while the heap has more than one element
    while (!pq.empty())
    {
        // extract:
        auto [count1, char1] = pq.top();
        pq.pop();

        // Check if we can add the current character
        if (ans.size() >= 2 && ans[ans.size() - 1] == char1 && ans[ans.size() - 2] == char1)
        {
            // If we already have two of char1, we need to use the second highest character
            if (pq.empty())
            {
                break; // If no other character is available, we are done
            }

            auto [count2, char2] = pq.top();
            pq.pop();

            ans += char2; // Add the second largest character
            count2--;        // Decrease its count

            if (count2 > 0)
            {
                pq.push({count2, char2});
            }

            // Put char1 back to heap to be considered in future iterations
            pq.push({count1, char1});
        }
        else
        {
            // Add char1 to the ans if it doesn't violate the condition
            ans += char1;
            count1--; // Decrease its count

            if (count1 > 0)
            {
                pq.push({count1, char1});
            }
        }
    }

    return ans;
}

int main()
{
    int a = 1;
    int b = 1;
    int c = 7;
    cout << "\nLongest possible happy string is: " << longestDiverseString(a, b, c);

    return 0;
}