/**
 * @file 1_1-hw1_1-use_postfix_to_calculate_value.c
 * @author 109403019 鄒翔宇
 * @brief hw1_1 use_postfix_to_calculate_value
 * @date 2022-10-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Declaration of max size of stack and max number of characters in the array in postfix expression*/
#define MAX_STACK_SIZE 41
#define MAX_POSTFIX_SIZE 41

/* Declaration of stack and its top pointer. -1 means empty. */
float stack[MAX_STACK_SIZE];
int top = -1;

/* Declaration of methods*/
void push(float item);
float pop();
int isEmpty(); // return 1 if the stack is empty, otherwise return 0
int isFull();  // return 1 if the stack is full, otherwise return 0
float evaluate_postfix(char postfix[]);
int is_invalid_input(char c); // return 1 if the input is invalid, otherwise return 0

int main()
{
    /* Declaration of variables */
    char input_postfix[MAX_POSTFIX_SIZE];
    int i = 0;
    char cur;
    float result;

    /* Get input postfix */
    while (i < MAX_POSTFIX_SIZE)
    {

        cur = getchar();
        input_postfix[i++] = cur;

        if (cur == '\n')
        {
            break;
        }
    }

    /* Get the result and output it. */
    result = evaluate_postfix(input_postfix);
    printf("%.2f", result);

    return 0;
}

void push(float item)
{
    // Check whether the stack overflow.
    if (isFull() == 1)
    {
        // printf("The stack overflow!");
        return;
    }

    // push item into stack
    stack[++top] = item;
}

float pop()
{
    // Check whether the stack is empty.
    if (isEmpty() == 1)
    {
        // printf("The stack is empty! Cannot do pop operation to stack!");
        return '$';
    }

    float deleted_item = stack[top--];

    return deleted_item;
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }

    return 0;
}

int isFull()
{
    if (top >= MAX_STACK_SIZE)
    {
        return 1;
    }

    return 0;
}

float evaluate_postfix(char postfix[])
{
    int i;
    char c;
    float sum, val1, val2;

    for (i = 0; postfix[i] != '\n' && i < MAX_POSTFIX_SIZE; i++)
    {
        c = postfix[i];

        if (isdigit(c))
        {
            push(c - '0');
        }
        else
        {
            float val1 = pop();
            float val2 = pop();

            switch (c)
            {
            case '+':
                sum = val2 + val1;
                break;
            case '-':
                sum = val2 - val1;
                break;
            case '*':
                sum = val2 * val1;
                break;
            case '/':
                sum = val2 / val1;
                break;
            default:
                break;
            }

            push(sum);
        }
    }

    return pop();
}

int is_invalid_input(char c)
{
    if (!isdigit(c) || c || '+' && c || '-' || c != '*' || c != '/')
    {
        return 1;
    }

    return 0;
}