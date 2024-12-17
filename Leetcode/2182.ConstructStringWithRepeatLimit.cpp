#include <bits/stdc++.h>
using namespace std;

string repeatLimitedString(string s, int repeatLimit)
{
    string ans = "";
    // no character must appear repeatLimit no of times together
    // in lexographical order ie z>y>x>___b>a

    // map to count freq of each characte:
    unordered_map<char, int> freq;
    for (auto it : s)
    {
        freq[it]++;
    }
    // max heap to store characters in lexographic order:
    priority_queue<pair<char, int>> maxHeap;
    for (auto it : freq)
    {
        maxHeap.push({it.first, it.second});
    }

    while (!maxHeap.empty())
    {
        // get topmost largest charcter & its freq
        auto [largestChar, largestFreq] = maxHeap.top();
        maxHeap.pop();

        // insert min of repeatLimit or largestFreq to ans string:
        ans.append(min(largestFreq, repeatLimit), largestChar);
        // now its freq decreases:
        largestFreq = largestFreq - min(largestFreq, repeatLimit);
        // add it back to heap if remaining characters left:
        if (largestFreq > 0)
        {
            // add a smaller charc first
            // if no charac available:
            if (maxHeap.empty())
            {
                break;
            }
            // get second largest charcter & its freq
            auto [secChar, secFreq] = maxHeap.top();
            maxHeap.pop();
            ans.push_back(secChar); // add it one time
            // reduce its freq:
            secFreq = secFreq - 1;
            // if its freq>0 then push back in heap:
            if (secFreq > 0)
            {
                maxHeap.push({secChar, secFreq});
            }
            maxHeap.push({largestChar, largestFreq});
        }
    }

    return ans;
}

int main()
{
    string s = "cczazcc";
    int repeatLimit = 3;
    cout << "\nString is: " << repeatLimitedString(s, repeatLimit);

    return 0;
}