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
    stack<node *> st;
    while (root != NULL || !st.empty())
    {
        // check if root exists
        if (root != NULL)
        {
            cout << root->data;
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            // null
            st.pop();
            root = root->right;
        }
    }
}

void inorder(node *root)
{
    // left root right
    stack<node *> st;
    while (root != NULL || !st.empty())
    {
        // check if root exists
        if (root != NULL)
        {
            // push
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            cout << root->data;
            // null
            st.pop();
            root = root->right;
        }
    }
}

vector<int> postorder_using2stacks(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    // left right root
    stack<node *> st1;
    stack<node *> st2;
    // push root in stakc1
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        // remove this from st1
        st1.pop();
        // add to st2
        st2.push(root);
        // check if left & right exists then add
        if (root->left != NULL)
        {
            st1.push(root->left);
        }
        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }
    // when stack1 is empt then add elem of stack2 in ans
    while (!st2.empty())
    {
        Node *elem = st2.top();
        ans.push_back(elem->data);
        st2.pop();
    }
    return ans;
}


// using only 1 stack:  
void postorder_using1stacks(node *root)
{
    // left right root
    stack<node *> st;
    while (root != NULL || !st.empty())
    {
        // check if root exists
        if (root != NULL)
        {
            cout << root->data;
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            // null
            st.pop();
            root = root->right;
        }
    }
}

int main()
{

    return 0;
}