#include <bits/stdc++.h>
using namespace std;

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
{
    // total numCourses courses labeled from 0 to numCourses - 1
    // prerequisites[i] = [ai, bi] :take course ai first if you want to take course bi + can also be indirect.
    // queries[j] = [uj, vj]  answer whether course uj is a prerequisite of course vj or not?
    // Return-> boolean array answer, where answer[j] is the answer to the jth query.
    vector<bool> answer;

    // consider each course as a node & build a isReachable matrix:
    vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
    // initially fill in direct pre-requisites:
    for (auto it : prerequisites)
    {
        isReachable[it[0]][it[1]] = true;
    }
    // now check for indirect pre-requisites:
    for (int i = 0; i < numCourses; i++)
    {
        for (int j = 0; j < numCourses; j++)
        {
            for (int k = 0; k < numCourses; k++)
            {
                if (isReachable[j][i] && isReachable[i][k])
                {
                    isReachable[j][k] = true;
                }
            }
        }
    }
    for (auto it : queries)
    {
        if (isReachable[it[0]][it[1]] == true)
        {
            answer.push_back(true);
        }
        else
        {
            answer.push_back(false);
        }
    }
    return answer;
}

int main()
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1, 2}, {1, 0}, {2, 0}};
    // 1->2
    // 1,2->0
    // 1->2->0
    vector<vector<int>> queries = {{1, 0}, {1, 2}, {2, 1}}; // T,T,F
    vector<bool> ans = checkIfPrerequisite(numCourses, prerequisites, queries);
    cout << "Ans:\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}