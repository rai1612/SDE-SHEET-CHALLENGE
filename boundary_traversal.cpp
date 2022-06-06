/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <bits/stdc++.h>
bool leaf(TreeNode<int> *root)
{
    return (root->left == NULL && root->right == NULL);
}
void left(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *curr = root->left;
    while (curr)
    {
        if (!leaf(curr))
            ans.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
        {
            curr = curr->right;
        }
    }
}

void leaf(TreeNode<int> *root, vector<int> &ans)
{
    if (leaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        leaf(root->left, ans);
    if (root->right)
        leaf(root->right, ans);
}

void right(TreeNode<int> *root, vector<int> &ans)
{
    stack<TreeNode<int> *> st;
    TreeNode<int> *curr = root->right;
    while (curr)
    {
        if (!leaf(curr))
            st.push(curr);
        if (curr->right)
            curr = curr->right;
        else
        {
            curr = curr->left;
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top()->data);
        st.pop();
    }
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    if (!leaf(root))
        ans.push_back(root->data);
    else
    {
        ans.push_back(root->data);
        return ans;
    }
    left(root, ans);
    leaf(root, ans);
    right(root, ans);
    return ans;
}