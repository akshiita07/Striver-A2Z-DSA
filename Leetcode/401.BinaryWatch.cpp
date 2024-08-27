#include <bits/stdc++.h>
using namespace std;

// count no of set bits: fnc
int countSetBits(int n)
{
    return __builtin_popcount(n);
}

vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> ans;
    // have total of 4+6 leds
    if (turnedOn > 8) // for valid hr:min
    {
        // empty as not possible
        return {};
    }
    // no of set bits in ans=turned on count

    // for hours: 0 to 11
    for (int i = 0; i < 12; i++)
    {
        // for mins: 0 to 59
        for (int j = 0; j < 60; j++)
        {
            // check for total count of set bits:
            if ((countSetBits(i) + countSetBits(j)) == turnedOn)
            {
                string hours = to_string(i);
                string mins;
                // append zero at beginning if length of j is only 1
                if (j < 10)
                {
                    mins = "0" + to_string(j);
                }
                else
                {
                    mins = to_string(j);
                }
                ans.push_back(hours + ':' + mins);
            }
        }
    }

    return ans;
}

int main()
{
    // read time
    // hours 2^0 to to 2^3 ie 1 to 8
    // min: 2^0 to 2^5 ie 1 to 32 available

    int turnedOn = 1; // represents the number of LEDs that are currently on
    // return all possible times the watch could represent

    vector<string> ans = readBinaryWatch(turnedOn);
    for (auto it : ans)
    {
        cout << it << "  ";
    }

    return 0;
}