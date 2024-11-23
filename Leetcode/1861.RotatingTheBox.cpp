#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
{
    int m = box.size();
    int n = box[0].size();
    // A stone '#'
    // A stationary obstacle '*'
    // Empty '.'
    // 90 degrees clockwise rotate box
    // some stones fall due to gravity until it lands on obstacle/another stone/bottom of the box
    // Return an n x m matrix representing the box after the rotation

    // move stones downwards until they reach another stone or an obstacle
    for (int i = 0; i < m; i++)
    {
        // track rightmost empty position hwere stone can fall due to gravity:
        int empty_space = n - 1;
        // traverse ROW from RIGHT TO LEFT:
        for (int j = n - 1; j >= 0; j--)
        {
            // if box is an obstacle then reset the empty position to one space before it:
            if (box[i][j] == '*')
            {
                empty_space = j - 1;
            }
            // if box is stone then swap stone posiiton with this empty space & reset the empty position to one space before it:
            if (box[i][j] == '#')
            {
                swap(box[i][j], box[i][empty_space]);
                empty_space--;
            }
        }
    }
    // rotate 90-> rows=colm & colm=rows
    int new_m = n;
    int new_n = m;
    vector<vector<char>> rotatedBox(new_m, vector<char>(new_n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // row same rahegi
            // colm switch hoga: m-i-1
            rotatedBox[j][m - 1 - i] = box[i][j];
        }
    }
    return rotatedBox;
}

int main()
{
    vector<vector<char>> box = {
        {'#', '#', '*', '.', '*', '.'},
        {'#', '#', '#', '*', '.', '.'},
        {'#', '#', '#', '.', '#', '.'}
    };
    vector<vector<char>> ans = rotateTheBox(box);
    cout << "Rotated matrix is: \n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    // Output: [['.',"#","#"],
    //      [".","#","#"],
    //      ["#","#",'*'],
    //      ["#",'*',"."],
    //      ["#",".",'*'],
    //      ["#",".","."]]

    return 0;
}