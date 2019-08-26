#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
}Node;

typedef struct t
{
    struct node* root;
}Tree;

void insert(Tree*, int);
void inorder_trav(Node*);
bool find(Tree*, int);
Node* min_node(Node*);
Node* delete(Node*, int);

int main(void)
{
    Tree tree;
    tree.root = NULL;
    insert(&tree, 3);
    insert(&tree, -3);
    insert(&tree, 6);
    insert(&tree, 10);
    insert(&tree, 12);
    insert(&tree, 2);
    insert(&tree, 1);
    inorder_trav(tree.root);
    printf("\n");
    if (find(&tree, 5)) printf("存在 5\n");
    else printf("不存在 5 \n");
    if (find(&tree, 12)) printf("存在12\n");
    else printf("不存在 12\n");

    if (find(&tree, -3)) printf("存在-3\n");
    else printf("不存在 12\n");
    if (find(&tree, 4)) printf("存在4\n");
    else printf("不存在 12\n");
    tree.root = delete(tree.root, 6);
    inorder_trav(tree.root);
    printf("\n");
    tree.root = delete(tree.root, 1);
    inorder_trav(tree.root);
    printf("\n");
    tree.root = delete(tree.root, 12);
    inorder_trav(tree.root);
    printf("\n");
    return 0;
}

Node* delete(Node* node, int val)
{
    if (node == NULL) return NULL;
    else if (node->val < val)
    {
        node->right = delete(node->right, val);
        return node;
    }
    else if (val < node->val)
    {
        node->left = delete(node->left, val);
        return node;
    }
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            return NULL;
        }
        else if (node->left != NULL && node->right != NULL)
        {
            Node* successor = min_node(node->right);
            node->val = successor->val;
            node->right = delete(node->right, successor->val);
            return node;
        }
        else if (node->left != NULL)
        {
            Node* left = node->left;
            free(node);
            return node->left;
        }
        else
        {
            Node* right = node->right;
            free(node);
            return node->right;
        }
    }
}

Node* min_node(Node* tmpnode)
{
    if (tmpnode == NULL) return;
    while(tmpnode != NULL)
    {
        if (tmpnode->left == NULL) return tmpnode;
        else tmpnode = tmpnode->left;
    }
}

bool find(Tree* tree, int val)
{
    Node* tmpnode = tree->root;
    while (tmpnode != NULL)
    {
        if (tmpnode->val == val) return true;
        else if (tmpnode->val < val) tmpnode = tmpnode->right;
        else tmpnode = tmpnode->left;
    }
    return false;
}

void inorder_trav(Node* node)
{
    if (node  == NULL) return ;
    inorder_trav(node->left);
    printf("%d\t", node->val);
    inorder_trav(node->right);

}

void insert(Tree* tree, int val)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    if (tree->root == NULL)
    {
        tree->root = node;
    }
    else
    {
        Node* tmpnode = tree->root;
        while(tmpnode)
        {
            if (tmpnode->val > val)
            {
                if (tmpnode->left == NULL) 
                {
                    tmpnode->left = node;
                    break;
                }
                else tmpnode = tmpnode->left;
            }
            else
            {
                if (tmpnode->right == NULL) 
                {
                    tmpnode->right = node;
                    break;
                }
                else tmpnode = tmpnode->right;
            }
        }
    }
}
