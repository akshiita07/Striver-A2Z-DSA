#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        long long nn = n;
        if (nn == 0) {
            return false;
        }
        if (((nn & (nn - 1)) == 0) && ((nn - 1) % 3 == 0)) {
            return true;
        } else {
            return false;
        }
    }
};

int main()
{
    
    return 0;
}