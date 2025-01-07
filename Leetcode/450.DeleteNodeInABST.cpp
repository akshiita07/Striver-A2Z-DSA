#include <bits/stdc++.h>
using namespace std;

TreeNode *helperLeft(TreeNode *root){
    // if left child does not exist then return right half
    if(root->left==NULL){
        return root->right;
    }
    // if right child does not exist then return left half
    if(root->right==NULL){
        return root->left;
    }
    // if both exists: delete right part then attach it to larger(extreme right) no of left part
    TreeNode* rightChild=root->right;
    TreeNode* extremeRight=findLastRight(root->left);   //of left part
    extremeRight->right=rightChild;
    return root->left;
}

TreeNode *findLastRight(TreeNode *root){
    // if null then return
    if(root->right==NULL){
        return root;
    }
    return findLastRight(root->right);
}
TreeNode *helperRight(TreeNode *root){
    // if left child does not exist then return right half
    if(root->left==NULL){
        return root->right;
    }
    // if right child does not exist then return left half
    if(root->right==NULL){
        return root->left;
    }
    // if both exists: delete left part then attach it to smallest(extreme left) no of right part
    TreeNode* leftChild=root->left;
    TreeNode* extremeLeft=findLastLeft(root->right);   //of left part
    extremeLeft->left=leftChild;
    return root->right;
}

TreeNode *findLastLeft(TreeNode *root){
    // if null then return
    if(root->left==NULL){
        return root;
    }
    return findLastLeft(root->left);
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    // if both left & right exists:
    // if deleting right part then attach it to larger(extreme right) no of left part
    // if deleting left part then attach it to smallest(extreme left) no of right part
    // else if one of d child is null then delete & directly connect remaining

    // if null binary tree given then:
    if(root==NULL){
        return NULL;
    }
    // if u have to delete root node:
    if(key==root->val){
        return helperLeft(root);
    }

    TreeNode * dummy_root=root;
    while(root!=NULL){
        if(root->val>key){
            // move to left
            if(root->left!=NULL && root->left->val==key){
                root->left=helperLeft(root->left);
            }else{
                // not found so keep traversing twds left:
                root=root->left;
            }
        }else{
            // right
            if(root->right!=NULL && root->right->val==key){
                root->right=helperLeft(root->right);
            }else{
                // not found so keep traversing twds right:
                root=root->right;
            }
        }
    }
    return dummy_root;

}

int main()
{

    return 0;
}