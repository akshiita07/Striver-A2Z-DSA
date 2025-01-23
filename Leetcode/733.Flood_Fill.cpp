#include <bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, vector<vector<int>> &coloredMatrix, vector<vector<int>> &image, int initialColor, int color)
{
    int m = image.size();
    int n = image[0].size();
    coloredMatrix[sr][sc] = color;
    // all 4 neighbours having this same initialColor have to be flooded:
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto dir : directions)
    {
        int row = sr + dir.first;
        int colm = sc + dir.second;
        // if in boundaries && color matches && not visited ie ans mai color is not updated yet:
        if (row >= 0 && row < m && colm >= 0 && colm < n && image[row][colm] == initialColor && coloredMatrix[row][colm] != color)
        {
            dfs(row, colm, coloredMatrix, image, initialColor, color);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    // image[i][j] represents the pixel value of the image
    // perform a flood fill on the image starting from the pixel image[sr][sc]
    int m = image.size();
    int n = image[0].size();
    // take a copy to store new ans:
    vector<vector<int>> coloredMatrix = image;

    // if color of starting pixel==color then no changes r made to image:
    if (image[sr][sc] == color)
    {
        return image;
    }

    int initialColor = image[sr][sc];
    dfs(sr, sc, coloredMatrix, image, initialColor, color);

    return coloredMatrix;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    vector<vector<int>> ans = floodFill(image, sr, sc, color);
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}