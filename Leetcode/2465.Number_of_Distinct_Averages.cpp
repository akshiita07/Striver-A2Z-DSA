class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        int n = nums.size();
        set<double> distinctAvg;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mini = nums[left];
            int maxi = nums[right];
            double avg = (mini + maxi) / 2.0;
            distinctAvg.insert(avg);
            left++;
            right--;
        }
        return distinctAvg.size(); // will give distinct set elements
    }
};