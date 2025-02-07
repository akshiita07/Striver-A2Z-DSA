#include <bits/stdc++.h>
using namespace std;

vector<int> queryResults(int limit, vector<vector<int>> &queries)
{
    // n*2 queries
    int n = queries.size();
    // (limit+1)balls numbered from 0 to limit
    // for every query (x,y) color the ball x with color y
    // find no of distinct colors of balls after each query is performed
    // result[i] vector denotes no of distinct colors after ith query
    unordered_map<int, int> colorOfEachBall;                        // ball<->color
    unordered_map<int, unordered_set<int>> ballsOfAParticularColor; // color<->{balls with that color}
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int ballNumber = queries[i][0];
        int ballColor = queries[i][1];

        // check if ball was previously colored:
        if (colorOfEachBall.find(ballNumber) != colorOfEachBall.end())
        {
            int oldColor = colorOfEachBall[ballNumber];
            // remove this ball number from the ballsOfAParticularColor set:
            ballsOfAParticularColor[oldColor].erase(ballNumber);
            // if this set becomes empty only then remove it:
            if (ballsOfAParticularColor[oldColor].empty())
            {
                ballsOfAParticularColor.erase(oldColor);
            }
        }

        colorOfEachBall[ballNumber] = ballColor;
        ballsOfAParticularColor[ballColor].insert(ballNumber);

        result.push_back(ballsOfAParticularColor.size());
    }

    return result;
}

int main()
{
    int limit = 4;
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}};
    // Output: [1,2,2,3,4]
    vector<int> ans = queryResults(limit, queries);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}