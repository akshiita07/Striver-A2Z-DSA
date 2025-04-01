#include <bits/stdc++.h>
using namespace std;

long long mostPoints(vector<vector<int>> &questions)
{
    // questions[i] = [pointsi, brainpoweri]
    // process questions in order & make decision whether to solve or skip question
    // solving question i gives points i no of points but Unable to solve next brainpower i no of questions
    // Return the maximum points you can earn for the exam
    // DP OPTION 1: solve ques i & get points[i] & jump to i+brainpower[i]+1 question & then solve it so points[i]+dp[i+brainpower[i]+1] (check if within bounds also!)
    // DP OPTION 2: skip ques i & jump to next question directly dp[i+1] (check if within bounds also!)
    // take maximum out of both dp options
    int n = questions.size();
    vector<long long> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int points = questions[i][0];
        int brainPower = questions[i][1];
        long long solve = points + (i + brainPower + 1 < n ? dp[i + brainPower + 1] : 0);
        long long skip = dp[i + 1];
        dp[i] = max(solve, skip);
    }
    return dp[0];
}

int main()
{
    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << "\nmaximum points you can earn for the exam= " << mostPoints(questions);

    return 0;
}