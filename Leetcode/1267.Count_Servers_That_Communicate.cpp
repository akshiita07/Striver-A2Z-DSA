#include <bits/stdc++.h>
using namespace std;

int countServers(vector<vector<int>> &grid)
{
    int m = grid.size();    // rows
    int n = grid[0].size(); // columns
    //  grid[i][j]==1 then server present else if 0 then NO server present
    // Two servers communicate if they are on the same row or on the same column
    // Return the number of servers that communicate with any other server
    vector<int> noOfServersInRow(m, 0);
    vector<int> noOfServersInColumn(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                noOfServersInRow[i]++;
                noOfServersInColumn[j]++;
            }
        }
    }

    int noOfCommunicatingServers = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if server is present then it must have someone in its row/colm to communicate other than that server itself so >1 (not>=1)
            if (grid[i][j] == 1 && (noOfServersInRow[i] > 1 || noOfServersInColumn[j] > 1))
            {
                noOfCommunicatingServers++;
            }
        }
    }

    return noOfCommunicatingServers;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    cout << "\nNumber of servers that communicate with any other server= " << countServers(grid);

    return 0;
}