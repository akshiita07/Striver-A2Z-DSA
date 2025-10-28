#include <bits/stdc++.h>
using namespace std;

int countValidSelections(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            // choose both dirn:
            for (int dir : {-1, 1})
            {
                // copy nums into new array
                vector<int> temp = nums;
                int curr = i; // where nums[i]=0
                // chosen curr and chosen dirn-L or R
                int d = dir;
                while (curr >= 0 && curr < n)
                {

                    if (temp[curr] == 0)
                    {
                        // increment if moving in R dirn
                        // decrement if moving in L dirn
                        curr += d;
                    }
                    else if (temp[curr] > 0)
                    {
                        temp[curr] -= 1;
                        // reverse dirn
                        d = d * (-1);
                        curr += d;
                    }
                }
                // check if all elements if temo are 0:
                bool isValid = true;
                for (int j = 0; j < temp.size(); j++)
                {
                    if (temp[j] != 0)
                    {
                        isValid = false;
                        break;
                    }
                }
                if (isValid)
                {
                    ans++;
                }
            }
        }
    }

    // A valid selection: every element in nums becomes 0 by the end of the process.
    // Return the number of possible valid selections.
    return ans;
}

int main()
{

    return 0;
}