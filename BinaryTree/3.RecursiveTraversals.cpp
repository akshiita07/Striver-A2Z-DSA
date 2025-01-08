#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor to initialise:
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(node *root)
{
    // root left right
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    // left root right
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

void postorder(node *root)
{
    // left right root
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}

vector<vector<int>> level_order(node *root)
{
    // BFS fashion
    vector<vector<int>> ans;
    queue<node*> q;
    // push root element in queue
    q.push(root);
    if(root==NULL){
        return ans;
    }
    // until queue is not empty:
    while(!q.empty()){
        // take size
        int n=q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            // take 1st elem
            node* newNode=q.front();
            q.pop();
            if(newNode->left!=NULL){
                q.push(newNode->left);
            }
            if(newNode->right!=NULL){
                q.push(newNode->right);
            }
            level.push_back(newNode->data);
        }
        ans.push_back(level);
    }
    return ans;
}

// part2:
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> preorder(TreeNode *root)
{
    vector<int> ans;
    // root left right
    if(root==NULL){
        return {};
    }
    ans.push_back(root->data);
    vector<int> leftAns=preorder(root->left);
    ans.insert(ans.end(),leftAns.begin(),leftAns.end());
    vector<int> rightAns=preorder(root->right);
    ans.insert(ans.end(),rightAns.begin(),rightAns.end());
    return ans;
}

vector<int> inorder(TreeNode *root)
{
    vector<int> ans;
    // left root right
    if(root==NULL){
        return {};
    }
    vector<int> leftAns=inorder(root->left);
    ans.insert(ans.end(),leftAns.begin(),leftAns.end());
    ans.push_back(root->data);
    vector<int> rightAns=inorder(root->right);
    ans.insert(ans.end(),rightAns.begin(),rightAns.end());
    return ans;
}

vector<int> postorder(TreeNode *root)
{
    vector<int> ans;
    // left right root
    if(root==NULL){
        return {};
    }
    vector<int> leftAns=postorder(root->left);
    ans.insert(ans.end(),leftAns.begin(),leftAns.end());
    vector<int> rightAns=postorder(root->right);
    ans.insert(ans.end(),rightAns.begin(),rightAns.end());
    ans.push_back(root->data);
    return ans;
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans;
    ans.push_back(inorder(root));
    ans.push_back(preorder(root));
    ans.push_back(postorder(root));
    return ans;
}

int main()
{

    return 0;
}