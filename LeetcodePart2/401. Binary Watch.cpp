class Solution {
public:
    int countSetBits(int n) { return __builtin_popcount(n); }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        // have total of 4+6 leds
        if (turnedOn > 8) // for valid hr:min
        {
            // empty as not possible
            return {};
        }
        // no of set bits in ans=turned on count

        // for hours: 0 to 11
        for (int i = 0; i < 12; i++) {
            // for mins: 0 to 59
            for (int j = 0; j < 60; j++) {
                // check for total count of set bits:
                if ((countSetBits(i) + countSetBits(j)) == turnedOn) {
                    string hours = to_string(i);
                    string mins;
                    // append zero at beginning if length of j is only 1
                    if (j < 10) {
                        mins = '0' + to_string(j);
                    } else {
                        mins = to_string(j);
                    }
                    ans.push_back(hours + ':' + mins);
                }
            }
        }

        return ans;
    }
};
