#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    // constructor to initialise:
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// pass track_parents as a &
void markParents(TreeNode *root, TreeNode *target, unordered_map<TreeNode *, TreeNode *> &track_parents)
{
    // BFS/level order TRAVERSAL
    // TAKE QUEUE
    queue<TreeNode *> qu;
    // PUSH ROOT
    qu.push(root);

    // traverse queue
    while (!qu.empty())
    {
        // pop first element
        TreeNode *elem = qu.front();
        qu.pop();
        // check if left exists
        if (elem->left)
        {
            // parent of elem->left is elem
            track_parents[elem->left] = elem;
            // push in qu
            qu.push(elem->left);
        }
        // check if right exists
        if (elem->right)
        {
            // parent of elem->right is elem
            track_parents[elem->right] = elem;
            // push in qu
            qu.push(elem->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    //   return an array of the values of all nodes that have a distance k from the target node
    vector<int> ans;

    // problem that we cannot travel in upward directions to find nodes reachable from top

    // have parent pointers:
    unordered_map<TreeNode *, TreeNode *> track_parents;
    // mark parents of every node using a hash map
    markParents(root, target, track_parents);

    // take visisted array:
    unordered_map<TreeNode *, bool> visited;
    // TAKE QUEUE
    queue<TreeNode *> qu;
    // push target element in it
    qu.push(target);
    // when pushed then mark it as visited
    visited[target] = true;

    // initially dist is 0
    int dist = 0;

    while (!qu.empty())
    {
        int n = qu.size();
        // if reached k:
        if (dist++ == k)
        {
            break;
        }

        // loop
        for (int i = 0; i < n; i++)
        {
            // pop first element
            TreeNode *elem = qu.front();
            qu.pop();
            // check if left exists & is NOT VISITED
            if (elem->left && !visited[elem->left])
            {
                // push in queue
                qu.push(elem->left);
                // mark it as visisted
                visited[elem->left] = true;
            }
            // check if right exists & is NOT VISITED
            if (elem->right && !visited[elem->right])
            {
                // push in queue
                qu.push(elem->right);
                // mark it as visisted
                visited[elem->right] = true;
            }
            // check for parent also if exists & not yet visited:
            if (track_parents.find(elem) != track_parents.end() && !visited[track_parents[elem]])
            {
                // push in queue
                qu.push(track_parents[elem]);
                // mark it as visisted
                visited[track_parents[elem]] = true;
            }
        }
    }

    // standing at target node perform a DFS traversal ie move either upwards or downwards
    // stop when dist==k

    while (!qu.empty())
    {
        TreeNode *elem = qu.front();
        qu.pop();
        ans.push_back(elem->data);
    }

    cout << "\nThe nodes that can be found at a dist of " << k << " are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode *target = root->left; // ie 5
    int k = 2;
    //   ie return those nodes that are at a dist of k=2 from target node ie 5
    distanceK(root, target, k);

    return 0;
}