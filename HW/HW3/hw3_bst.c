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
Input:
8
10 5 6 13 4 9 7 1

Output:
Preorder: 10 5 4 1 6 9 7 13
Inorder: 1 4 5 6 7 9 10 13
Postorder: 1 4 7 9 6 5 13 10

-------------------------------------------------------------

Test2
Input:
-1

Output:

-------------------------------------------------------------

Test3
Input:
100
206 150 323 185 30 400 13 18 141 307 271 389 91 71 331 290 32 357 19 276 35 162 223 156 127 52 86 90 326 336 242 187 37 367 257 50 371 8 24 333 294 93 293 247 28 318 353 77 358 198 321 195 41 188 158 279 319 343 215 45 102 17 88 131 40 278 149 161 25 273 130 31 337 376 166 145 227 304 258 356 213 44 391 98 193 173 49 144 243 138 374 106 36 154 109 282 217 369 182 76

Output:
Preorder: 206 150 30 13 8 18 17 19 24 28 25 141 91 71 32 31 35 52 37 36 50 41 40 45 44 49 86 77 76 90 88 127 93 102 98 106 109 131 130 138 149 145 144 185 162 156 154 158 161 166 173 182 187 198 195 188 193 323 307 271 223 215 213 217 242 227 257 247 243 258 290 276 273 279 278 282 294 293 304 318 321 319 400 389 331 326 357 336 333 353 343 337 356 367 358 371 369 376 374 391
Inorder: 8 13 17 18 19 24 25 28 30 31 32 35 36 37 40 41 44 45 49 50 52 71 76 77 86 88 90 91 93 98 102 106 109 127 130 131 138 141 144 145 149 150 154 156 158 161 162 166 173 182 185 187 188 193 195 198 206 213 215 217 223 227 242 243 247 257 258 271 273 276 278 279 282 290 293 294 304 307 318 319 321 323 326 331 333 336 337 343 353 356 357 358 367 369 371 374 376 389 391 400
Postorder: 8 17 25 28 24 19 18 13 31 36 40 44 49 45 41 50 37 52 35 32 76 77 88 90 86 71 98 109 106 102 93 130 138 131 127 91 144 145 149 141 30 154 161 158 156 182 173 166 162 193 188 195 198 187 185 150 213 217 215 227 243 247 258 257 242 223 273 278 282 279 276 293 304 294 290 271 319 321 318 307 326 333 337 343 356 353 336 358 369 374 376 371 367 357 331 391 389 400 323 206

*/