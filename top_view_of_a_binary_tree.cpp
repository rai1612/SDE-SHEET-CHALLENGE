/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    map<int, TreeNode<int> *> level_node;
    while (!q.empty())
    {
        TreeNode<int> *node = q.front().first;
        int level = q.front().second;
        q.pop();
        if (level_node.find(level) == level_node.end())
        {
            level_node[level] = node;
        }
        if (node->left)
            q.push({node->left, level - 1});
        if (node->right)
            q.push({node->right, level + 1});
    }
    for (auto i : level_node)
    {
        ans.push_back(i.second->val);
    }
    return ans;
}