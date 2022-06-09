/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {                                     // only if there is left, we can go to its rightmost node
            TreeNode<int> *prev = curr->left; // Moving to the left subtree so that we can now go to the rightmost node of it
            while (prev->right)
            {
                prev = prev->right; // moving to the rightmost node of the left subtree
            }
            prev->right = curr->right; // pointing the right of rightmost node of the left subtree of curr to curr's right
            curr->right = curr->left;  // because we are moving only to curr's right
        }
        curr = curr->right; // moving to the next node after the required sequence is done for curr
    }
    return root;
}