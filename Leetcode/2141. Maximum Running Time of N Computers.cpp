#include <bits/stdc++.h>
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        // n computers
        // ith battery can run a computer for batteries[i] minutes
        // run all n computers simultaneously using given batteries
        // return max no of minutes they run simultaneously
        long long sumPower = 0;
        for (auto it : batteries) {
            sumPower += it;
        }
        long long left = 1;
        long long right = sumPower / n;
        // binary search
        while (left < right) {
            long long target = right - (right - left) / 2;
            long long extra = 0;

            for (auto it : batteries) {
                extra += min((long long)it, target);
            }

            if (extra >= (long)(n * target)) {
                left = target;
            } else {
                right = target - 1;
            }
        }
        return left;
    }
};
