#include <bits/stdc++.h>
using namespace std;

bool canCross(vector<int> &stones)
{
    // if prev jump was of k units then next jump must be of either k-1,k,k+1 units
    // first jump is always 1 unit
}

int main()
{
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << "\nCan the frog cross the river? " << canCross(stones);
    return 0;
}
