#include <bits/stdc++.h>
using namespace std;

int findAreaOfHistogram(vector<int> &matrix)
{
    int maxArea = 0;
    int n = matrix.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && matrix[st.top()] > matrix[i])
        {
            int elem = matrix[st.top()];
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse - pse - 1) * elem);
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int elem = matrix[st.top()];
        st.pop();
        int nse = n;
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, (nse - pse - 1) * elem);
    }
    return maxArea;
}
// TIME: O(n*m)->for prefix sum + O(n)*(2n)->for histogram  ==  O(n2)
// SPACE: O(n*m)->prefix sum + O(n)->for stack n histogram
int maximalRectangle(vector<vector<char>> &matrix)
{
    // for each row of matrix consider histogram bars that start with '1'
    // do not consideer bars starting from 0
    int rows = matrix.size();     // n
    int colms = matrix[0].size(); // m
    int maxArea = 0;
    vector<vector<int>> prefixSumMatrix(rows, vector<int>(colms,0));

    // find top to bottom sums for prefix sum
    for (int i = 0; i < colms; i++)
    {
        int sum = 0;
        for (int j = 0; j < rows; j++)
        {
            int elem;
            if (matrix[j][i] == '0')
            {
                elem = 0;
            }
            else if (matrix[j][i] == '1')
            {
                elem = 1;
            }
            sum += elem;
            if (matrix[j][i] == '0')
            {
                sum = 0;
            }
            prefixSumMatrix[j][i] = sum;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        maxArea = max(maxArea, findAreaOfHistogram(prefixSumMatrix[i]));
    }
    return maxArea;
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << "\nThe maximum area of continuous 1s is: " << maximalRectangle(matrix);

    return 0;
}