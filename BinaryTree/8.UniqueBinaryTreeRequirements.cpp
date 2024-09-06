// what kinds of traversals r reqd to construct a UNIQUE BINARY TREE

// 1. preorder & postorder
// (root left right) & (left right root)
// different trees possible so NOT UNIQUE

// 2. inorder & preorder
// (left root right) & ( root left right)
// UNIQUE tree possible!! :)

// 3. inorder & postorder
// (left root right) & ( left right root)
// UNIQUE tree possible!! :)

// inorder is imp to get unique BT
#include <bits/stdc++.h>
using namespace std;


bool isPossible(int a, int b)
{
    // Each traversal is represented with an integer: preorder - 1, inorder - 2, postorder - 3.   
    if((a==2 || b==2) && a!=b){
        return true;
    }
    return false;
}