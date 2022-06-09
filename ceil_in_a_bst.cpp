/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void solve(BinaryTreeNode<int> *root, int x, int &ans)
{
    if (root == NULL)
        return;
    if (root->data == x)
    {
        ans = x;
        return;
    }
    else if (root->data < x)
        solve(root->right, x, ans);
    else
    {
        ans = root->data;
        solve(root->left, x, ans);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ans = -1;
    solve(node, x, ans);
    return ans;
}