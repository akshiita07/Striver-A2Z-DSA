#include <bits/stdc++.h>
using namespace std;

vector<int> treeQueries(TreeNode *root, vector<int> &queries)
{
    // Create a map to store the depth of each TreeNode.
    unordered_map<TreeNode *, int> depthMap;

    // Recursive lambda function to calculate depth of nodes.
    // It returns the depth of the given node.
    function<int(TreeNode *)> calculateDepth = [&](TreeNode *node) -> int
    {
        if (!node)
            return 0;
        int leftDepth = calculateDepth(node->left);
        int rightDepth = calculateDepth(node->right);
        depthMap[node] = 1 + max(leftDepth, rightDepth);
        return depthMap[node];
    };
    // Call the recursive function to calculate depths.
    calculateDepth(root);

    // Create a results vector for the maximum rest (extra information you can gather while staying in that node)
    // for each node value, plus 1 for the case where node value is 0.
    vector<int> maximumRest(depthMap.size() + 1);

    // Recursive lambda function for depth-first search to populate the rest values for each node.
    function<void(TreeNode *, int, int)> dfs = [&](TreeNode *node, int depth, int rest)
    {
        if (!node)
            return;
        ++depth;
        maximumRest[node->val] = rest;

        // Visit left and right children with updated 'rest'
        dfs(node->left, depth, max(rest, depth + depthMap[node->right]));
        dfs(node->right, depth, max(rest, depth + depthMap[node->left]));
    };
    // Initialize DFS with root node, depth as -1, and rest as 0.
    dfs(root, -1, 0);

    // Answer vector to store results for the given queries
    vector<int> answers;

    // Loop over each query and fetch the corresponding rest value.
    for (int value : queries)
    {
        answers.push_back(maximumRest[value]);
    }
    return answers;
}

int main()
{

    return 0;
}