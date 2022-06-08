/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include <bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    vector<int> pre, in, post;
    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        BinaryTreeNode<int> *node = st.top().first;
        int id = st.top().second;
        st.pop();
        if (id == 1)
        {
            pre.push_back(node->data);
            id++;
            st.push({node, id});
            if (node->left)
                st.push({node->left, 1});
        }
        else if (id == 2)
        {
            in.push_back(node->data);
            id++;
            st.push({node, id});
            if (node->right)
                st.push({node->right, 1});
        }
        else
        {
            post.push_back(node->data);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}