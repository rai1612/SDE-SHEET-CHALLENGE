/************************************************************

    Following is the TreeNode class structure

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
int solve(TreeNode<int> *root, int &ans)
{
    if (root == NULL)
        return 0;

    int lh = solve(root->left, ans);
    int rh = solve(root->right, ans);
    ans = max(ans, lh + rh); // for any node, the diameter = lh+rh

    return max(lh, rh) + 1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int ans = 0;
    solve(root, ans);
    return ans;
}
