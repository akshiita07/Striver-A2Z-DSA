#include <bits/stdc++.h>
using namespace std;

int numRabbits(vector<int> &answers)
{
    // answer[i]=no of rabbits having same color as rabbit i
    // return the minimum number of rabbits that could be in the forest
    // ans=no of unique elements in array + unka count
    int ans = 0;
    unordered_map<int, int> hashMap;
    int n = answers.size();
    for (int i = 0; i < n; i++)
    {
        if (hashMap[answers[i]] == 0)
        {
            ans += answers[i] + 1;
            hashMap[answers[i]] = answers[i];
        }
        else
        {
            hashMap[answers[i]]--;
        }
    }
    return ans;
}

int main()
{
    vector<int> answers = {1, 1, 2};
    cout << "\nminimum number of rabbits that could be in the forest= " << numRabbits(answers);

    return 0;
}