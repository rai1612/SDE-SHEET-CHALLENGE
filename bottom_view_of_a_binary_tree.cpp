/*************************************************************

    Following is the Binary Tree node structure.

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

*************************************************************/
#include <bits/stdc++.h>
vector<int> bottomView(BinaryTreeNode<int> *root)
{

    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});

    map<int, BinaryTreeNode<int> *> mp;

    while (!q.empty())
    {
        BinaryTreeNode<int> *node = q.front().first;
        int level = q.front().second;
        q.pop();
        mp[level] = node;

        if (node->left)
            q.push({node->left, level - 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    for (auto i : mp)
        ans.push_back(i.second->data);
    return ans;
}
