#include <bits/stdc++.h>
using namespace std;

int slidingPuzzle(vector<vector<int>> &board)
{
    // 2*3 board with numbers from 1 to 5 and empty denoted by 0
    // [[1,2,3],[4,5,0]] op
    // return the least number of moves required so that the state of the board is solved
    string target = "123450";    // The solved state
    string convertedString = ""; // Convert board to a string
    // converted elements in matrix to string
    for (auto &it : board)
    {
        for (auto elem : it)
        {
            convertedString += to_string(elem);
        }
    }

    // If already solved
    if (convertedString == target)
    {
        return 0;
    }

    // Adjacency list of valid swaps for each position in the 2x3 board
    vector<vector<int>> moves = {
        {1, 3},    // 0 -> can swap with positions 1 and 3 ie right & down
        {0, 2, 4}, // 1 -> can swap with positions 0, 2, and 4 ie left right & down
        {1, 5},    // 2 -> can swap with positions 1 and 5 ie left & down
        {0, 4},    // 3 -> can swap with positions 0 and 4 ie up & right
        {1, 3, 5}, // 4 -> can swap with positions 1, 3, and 5 ie left,right & up
        {2, 4}     // 5 -> can swap with positions 2 and 4 is left & up
    };

    // {board state, number of moves}
    queue<pair<string, int>> q;
    unordered_set<string> visited; // To avoid revisiting states

    q.push({convertedString, 0});
    visited.insert(convertedString);

    // bfs
    while (!q.empty())
    {
        auto [currentString, steps] = q.front();
        q.pop();

        // Find the position of '0'
        int zeroPos = currentString.find('0');

        // Explore all possible moves
        for (int nextPos : moves[zeroPos])
        {
            string nextString = currentString;
            swap(nextString[zeroPos], nextString[nextPos]); // Swap 0 with the adjacent tile

            // If solved
            if (nextString == target)
            {
                return steps + 1;
            }

            // If not visited
            if (visited.find(nextString) == visited.end())
            {
                q.push({nextString, steps + 1});
                visited.insert(nextString);
            }
        }
    }

    return -1; // If no solution is found
}

int main()
{
    vector<vector<int>> board = {{1, 2, 3}, {4, 0, 5}};
    cout << "\nLeast number of moves required r: " << slidingPuzzle(board);
    return 0;
}