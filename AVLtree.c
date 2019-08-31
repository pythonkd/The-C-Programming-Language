#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct tree
{
    Node* root;
}Tree;

void insert(Tree* tree, int);
void inorder_trav(Node*);

int main(void)
{
    Tree tree;
    tree.root = NULL;
    insert(&tree, 5);
    insert(&tree, 16);
    insert(&tree, 8);
    insert(&tree, 9);
    insert(&tree, 10);
    insert(&tree, 11);
    printf("%d %d %d \n", tree.root->data, tree.root->left->data, tree.root->right->data);
    inorder_trav(tree.root);
    return 0;
}

void inorder_trav(Node* node)
{
    if (node == NULL) return;
    else
    {
        inorder_trav(node->left);
        printf("%d\t", node->data);
        inorder_trav(node->right);
    }
}

void insert(Tree* tree, int val)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    int tmp;
    if (tree->root == NULL)
    {
        tree->root = node;
    }
    else
    {
        Node* tmpnode = tree->root;
        while (tmpnode != NULL)
        {
            if (tmpnode->data < val)
            {
                if (tmpnode->left != NULL)
                {
                    if (tmpnode->right != NULL) tmpnode = tmpnode->right;
                    else
                    {
                        tmpnode->right = node;
                        return;
                    }
                }
                else
                {
                    if (tmpnode->right == NULL)
                    {
                        tmpnode->right = node;
                        return;
                    }
                    else
                    {
                        if (tmpnode->right->data < val)
                        {
                            tmp = tmpnode->right->data;
                            tmpnode->right->data = node->data;
                            node->data = tmp;
                            tmp = tmpnode->data;
                            tmpnode->data = node->data;
                            node->data = tmp;
                            tmpnode->left = node;
                        }
                        else
                        {
                            tmp = tmpnode->data;
                            tmpnode->data = node->data;
                            node->data = tmp;
                            tmpnode->left = node;
                        }
                    }
                }
            }
            else
            {   
                if (tmpnode->right != NULL)
                {
                    if (tmpnode->left != NULL) tmpnode = tmpnode->left;
                    else
                    {
                        tmpnode->left = node;
                        return;
                    }
                }
                else
                {
                    if (tmpnode->left == NULL)
                    {
                        tmpnode->left = node;
                        return;
                    }
                    if (tmpnode->left->data < val)
                    {
                        tmp = tmpnode->data;
                        tmpnode->data = node->data;
                        node->data = tmp;
                        tmpnode->right = node;
                    }
                    else
                    {
                        tmp = tmpnode->left->data;
                        tmpnode->left->data = node->data;
                        node->data = tmp;
                        tmp = tmpnode->data;
                        tmpnode->data = node->data;
                        node->data = tmp;
                        tmpnode->right = node;
                    }
                }
            }
        }
    }
}
