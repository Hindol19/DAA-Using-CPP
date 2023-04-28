#include <iostream>
using namespace std;

class BinaryTree
{

    int data;
    BinaryTree *right;
    BinaryTree *left;

public:
    BinaryTree()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    BinaryTree(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
    BinaryTree *insertNode(BinaryTree *root, int x)
    {
        if (root == NULL)
        {
            return new BinaryTree(x);
        }
        else
        {
            BinaryTree *temp = root;
            if (x > temp->data)
            {
                root->right = insertNode(temp->right, x);
            }
            else
            {
                root->left = insertNode(temp->left, x);
            }
            return root;
        }
    }
    void inorder(BinaryTree *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(BinaryTree *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(BinaryTree *root)
    {
        if (root == NULL)
            return;
        preorder(root->left);
        preorder(root->right);
        cout << root->data << " ";
    }
};

int main()
{
    BinaryTree b1;
    BinaryTree *root = NULL;
    root = b1.insertNode(root, 2);
    root = b1.insertNode(root, 6);
    root = b1.insertNode(root, 12);
    root = b1.insertNode(root, 7);
    root = b1.insertNode(root, 29);
    b1.inorder(root);
    return 0;
}