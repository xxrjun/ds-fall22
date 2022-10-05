/**
 * @file 1_2-infix_to_prefix.c
 * @author your name (you@domain.com)
 * @brief NCU DS fall 2022 HW1_2 infix to prefix
 * @date 2022-10-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Declaration of max size of stack and max number of characters in the array in postfix expression*/
#define MAX_STACK_SIZE 41
#define MAX_ARR_SIZE 41

/* Declaration of stack and its top pointer. -1 means empty. */
float stack[MAX_STACK_SIZE];
int top = -1;

/* Declaration of methods*/
void push(char item);                                                            // push item into stack
char pop();                                                                      // pop item from stack
int isEmpty();                                                                   // return 1 if the stack is empty, otherwise return 0
int isFull();                                                                    // return 1 if the stack is full, otherwise return 0
int get_priority(char c);                                                        // return the priority of character
int is_invalid_input(char c);                                                    // return 1 if the input is invalid, otherwise return 0
void infix_to_prefix(char input_infix[MAX_ARR_SIZE], char prefix[MAX_ARR_SIZE]); // turn infix to prefix expression
void reverse(char str[MAX_ARR_SIZE], int len);                                   // reverse

int main()
{
    /* Declaration of variables */
    char input_infix[MAX_ARR_SIZE], prefix[MAX_ARR_SIZE];
    int i = 0, len = 0;
    char cur;
    float result;

    /* Get input in infix expression */
    while (i < MAX_ARR_SIZE)
    {

        cur = getchar();
        input_infix[i++] = cur;

        /* If input char is end of line or is invalid input, break while loop. */
        if (cur == '\n' || is_invalid_input(cur) == 1)
        {
            break;
        }
    }

    len = i;
    // reverse(prefix, len);

    /* Turn infix to prefix and output it */
    // infix_to_prefix(input_infix, prefix);
    printf("%c\n", input_infix[2]);

    return 0;
}

void reverse(char str[MAX_ARR_SIZE], int len)
{
    char temp;

    for (int i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
int get_priority(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
}

void push(char item)
{
    // Check whether the stack overflow.
    if (isFull() == 1)
    {
        return;
    }

    // push item into stack
    stack[++top] = item;
}

char pop()
{
    // Check whether the stack is empty.
    if (isEmpty() == 1)
    {
        // printf("The stack is empty! Cannot do pop operation to stack!");
        return '$';
    }

    // Get the deleted item to return
    char deleted_item = stack[top--];

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

int is_invalid_input(char c)
{
    // Only digits, '+', '-', '*' and '/' is valid.
    if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
    {
        return 1;
    }

    return 0;
}