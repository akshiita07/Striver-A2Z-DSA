#include <bits/stdc++.h>
using namespace std;

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();

    // Convert the board to a 1D array
    vector<int> cells(n * n + 1, -1);
    int index = 1;
    bool leftToRight = true;

    for (int i = n - 1; i >= 0; i--)
    {
        if (leftToRight)
        {
            for (int j = 0; j < n; j++)
            {
                cells[index++] = board[i][j];
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cells[index++] = board[i][j];
            }
        }
        leftToRight = !leftToRight;
    }

    // BFS
    queue<int> q;
    vector<bool> visited(n * n + 1, false);

    q.push(1);
    visited[1] = true;
    int moves = 0;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            int curr = q.front();
            q.pop();

            if (curr == n * n)
                return moves;

            for (int dice = 1; dice <= 6; dice++)
            {
                int next = curr + dice;
                if (next > n * n)
                {
                    continue;
                }

                int dest = (cells[next] != -1) ? cells[next] : next;

                if (!visited[dest])
                {
                    visited[dest] = true;
                    q.push(dest);
                }
            }
        }
        moves++;
    }

    return -1; // Not reachable
}

int main()
{
    vector<vector<int>> board = {{}};

    return 0;
}