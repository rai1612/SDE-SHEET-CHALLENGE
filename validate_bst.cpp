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
bool isBST(BinaryTreeNode<int> *root, int mn, int mx)
{
    if (root == NULL)
        return true;
    if (root->data < mn || root->data > mx)
        return false;
    return isBST(root->left, mn, root->data) && isBST(root->right, root->data, mx);
}
bool validateBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    return isBST(root, INT_MIN, INT_MAX);
}