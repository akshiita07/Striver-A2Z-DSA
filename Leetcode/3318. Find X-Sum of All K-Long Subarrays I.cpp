#include <bits/stdc++.h>
using namespace std;

vector<int> findXSum(vector<int> &nums, int k, int x)
{
    int n = nums.size();
    // answer vector return where answer[i]=x-sum of subarray nums[i..i + k
    // - 1]
    vector<int> answer;
    for (int i = 0; i <= n - k; i++)
    { // occ of all elem in array:
        unordered_map<int, int> occOfElem;
        for (int j = i; j < i + k; j++)
        {
            occOfElem[nums[j]]++;
        }
        // keep occ of top x most freq elements (if tie-> elem with bigger
        // value)
        vector<pair<int, int>> freqVec;
        for (auto &it : occOfElem)
        {
            freqVec.push_back({it.first, it.second});
        }

        sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b)
             {
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second; });

        // keep only top x distinct elements
        unordered_set<int> distinctMaxElem;
        for (int j = 0; j < min(x, (int)freqVec.size()); j++)
        {
            distinctMaxElem.insert(freqVec[j].first);
        }

        // sum of array
        int sum = 0;
        for (int j = i; j < i + k; j++)
        {
            if (distinctMaxElem.count(nums[j]))
                sum += nums[j];
        }

        answer.push_back(sum);
    }

    return answer;
}

int main()
{

    return 0;
}