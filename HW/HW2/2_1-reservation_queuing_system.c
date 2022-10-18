/**
 * @file 2_1-reservation_queuing_system.c
 * @author NCU MIS 109403019 鄒翔宇 [@xxrjun](https://github.com/xxrjun)
 * @brief
 * @version 1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

/* Struct variable of Queue. */
typedef struct
{
    struct Guest *guests[MAX_SIZE];
    int rear;
    int front;
    int size;

    struct Guest
    {
        char guest_id;
        int num_of_guests;
    };
} Queue;

/* Declaration of functions. */
Queue *create_queue();                                       // create a circular queue.
struct Guest *creat_guest(char guest_id, int num_of_guests); // create a new group of guests.
void enqueue(Queue *q, struct Guest *guest);
void dequeue(Queue *q);
void add_new_guests(Queue *q);
void bring_guest_in(Queue *q);
int is_queue_empty(Queue *q);
int is_queue_full(Queue *q);
void print_front_guest(Queue *q);
void print_total_guests_num(Queue *q);
void print_out_error();

/* Entry point: main function*/
int main()
{
    Queue *queue = create_queue();

    int input_operation = 0;
    int exit = 0;

    while (!exit)
    {
        scanf("%d", &input_operation);
        switch (input_operation)
        {
        case 1: /* Add a new group of guest into queue. */
            add_new_guests(queue);
            break;
        case 2: /* Output how many guests in queue. */
            print_total_guests_num(queue);
            break;
        case 3: /* Output the front guest of queue. */
            print_front_guest(queue);
            break;
        case 4: /* Bring front guest into restaurant, delete front of queue. */
            bring_guest_in(queue);
            break;
        case -1: /* Exit */
            exit = 1;
            break;
        default: /* Others, print out error. */
            print_out_error();
            break;
        }
    }

    return 0;
}

Queue *create_queue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;

    return q;
}

struct Guest *creat_guest(char guest_id, int num_of_guests)
{
    struct Guest *guest = (struct Guest *)malloc(sizeof(struct Guest));
    guest->guest_id = guest_id;
    guest->num_of_guests = num_of_guests;
}

int is_queue_full(Queue *q)
{
    if (q->size == MAX_SIZE)
    {
        return 1;
    }

    return 0;
}

int is_queue_empty(Queue *q)
{
    if (q->size == 0)
    {
        return 1;
    }

    return 0;
}

void enqueue(Queue *q, struct Guest *guest)
{
    if (!is_queue_full)
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->guests[q->rear] = guest;
        q->size++;
    }
}

void dequeue(Queue *q)
{
    if (!is_queue_empty)
    {

        struct Guest *deleted_guest = q->guests[q->front];
        q->front == (q->front + 1) % MAX_SIZE;
        free(deleted_guest);
        q->size--;
    }
}

void add_new_guests(Queue *q)
{
    char guest_id;
    int num_of_guests;

    scanf("%c %d", &guest_id, &num_of_guests);

    struct Guest *new_guest = creat_guest(guest_id, num_of_guests);

    enqueue(q, new_guest);
}

void bring_guest_in(Queue *q)
{
    dequeue(q);
}

void print_front_guest(Queue *q)
{
    char front_guest_id = q->guests[q->front]->guest_id;
    printf("%c", front_guest_id);
}

void print_total_guests_num(Queue *q)
{
    if (is_queue_empty(q))
    {
        printf("%d\n", 0);
    }
    else
    {
        int total_num = 0;
        int cur_group_guest_num = 0;

        for (int i = 0; i < q->size; i++)
        {
            cur_group_guest_num = q->guests[q->front + i]->num_of_guests;
            total_num += cur_group_guest_num;
        }

        printf("%d\n", total_num);
    }
}

void print_out_error()
{
    printf("error\n");
}