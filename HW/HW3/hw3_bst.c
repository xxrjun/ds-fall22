/**
 * @file hw3_bst.c
 * @author MIS 109403019 鄒翔宇
 * @brief NCU DS Fall22 HW3 Binary Search Tree
 * @version 0.1
 * @date 2022-11-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

/* Node struct */
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

} Node;

/* Declaration of functions */
Node *newNode(int data);
Node *insert(Node *node, int data);
void preorder(Node *node);
void inorder(Node *node);
void postorder(Node *node);

/* Entry point */
int main()
{
    int n = 0;
    scanf("%d", &n);

    // exit if n is -1
    if (n == -1)
    {
        return 0;
    }

    int input = 0;
    scanf("%d", &input);

    Node *head = newNode(input);

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &input);
        head = insert(head, input);
    }

    printf("Preorder: ");
    preorder(head);
    printf("\n");

    printf("Inorder: ");
    inorder(head);
    printf("\n");

    printf("Postorder: ");
    postorder(head);
    printf("\n");
}

/**
 * @brief Create a new node.
 *
 * @param data
 * @return Node*
 */
Node *newNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/**
 * @brief Insert a node into the binary tree.
 *
 * @param node
 * @param data
 * @return Node*
 */
Node *insert(Node *node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

/**
 * @brief Preorder traversal
 *
 * @param node
 */
void preorder(Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

/**
 * @brief Inorder traversal
 *
 * @param node
 */
void inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

/**
 * @brief Postorder traversal
 *
 * @param node
 */
void postorder(Node *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

/* Test cases

Test1
input:
8
10 5 6 13 4 9 7 1
output:
Preorder: 10 5 4 1 6 9 7 13
Inorder: 1 4 5 6 7 9 10 13
Postorder: 1 4 7 9 6 5 13 10

-------------------------------------------------------------

*/