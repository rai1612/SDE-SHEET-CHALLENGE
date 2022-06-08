/*************************************************************

    Following is the Binary Tree node structure

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
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    // We will use stack here
    stack<BinaryTreeNode<int> *> currLevel, nextLevel;
    currLevel.push(root);

    // We have to actually start from right to left as when taking the root, the direction does not matter and also it is default left to right, so actual traversing start from right to left
    bool right_to_left = true;
    while (!currLevel.empty())
    {
        BinaryTreeNode<int> *node = currLevel.top();
        currLevel.pop();
        ans.push_back(node->data);
        if (right_to_left)
        {
            // In the stack it is reversed, so when right_to_left is true it means we have to go right to left, so left is pushed first and then right is pushed into the stack
            if (node->left)
                nextLevel.push(node->left);
            if (node->right)
                nextLevel.push(node->right);
        }
        else
        {
            // In the stack it is reversed, so when right_to_left is false it means we have to go left to right, so right is pushed first and then left is pushed into the stack
            if (node->right)
                nextLevel.push(node->right);
            if (node->left)
                nextLevel.push(node->left);
        }

        // When the traversal of a particular level is completed, we have to change the direction and also the nextLevel becomes the currLevel now
        if (currLevel.empty())
        {
            right_to_left = !right_to_left;
            swap(currLevel, nextLevel);
        }
    }
}
