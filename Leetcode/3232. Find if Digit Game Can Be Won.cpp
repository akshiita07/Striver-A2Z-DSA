class Solution
{
public:
    bool canAliceWin(vector<int> &nums)
    {
        // check all single digit numbers & put in one array & then check sum:
        vector<int> alice;
        vector<int> bob;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 9)
            {
                // single digit
                alice.push_back(nums[i]);
            }
            else
            {
                // double digit
                bob.push_back(nums[i]);
            }
        }
        int aliceSum = accumulate(alice.begin(), alice.end(), 0);
        int bobSum = accumulate(bob.begin(), bob.end(), 0);
        if (aliceSum > bobSum || bobSum > aliceSum)
        {
            return true;
        }
        return false;
    }
};