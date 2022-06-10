/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
int predecessor(BinaryTreeNode<int> *root, int key)
{
    int pred = -1;
    while (root)
    {
        if (root->data < key)
        {
            pred = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return pred;
}
int successor(BinaryTreeNode<int> *root, int key)
{
    int succ = -1;
    while (root)
    {
        if (root->data > key)
        {
            succ = root->data;
            root = root->left;
        }
        else
            root = root->right;
    }
    return succ;
}
pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    int pred = predecessor(root, key);
    int succ = successor(root, key);
    return {pred, succ};
}
