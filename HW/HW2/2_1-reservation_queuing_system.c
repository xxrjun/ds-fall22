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
    struct Guest
    {
        char guest_id;
        int num_of_guests;
    } Guest;

    struct Guest *guests[MAX_SIZE];
    int rear;
    int front;
    int size;
} Queue;

/* Declaration of functions. */
Queue *create_queue();                                       // create a circular queue.
struct Guest *creat_guest(char guest_id, int num_of_guests); // create a new group of guests.
void enqueue(Queue *q, struct Guest *guest);
void dequeue(Queue *q);
void add_new_guests(Queue *q);
void bring_guest_in(Queue *q);
int is_queue_empty(Queue *q); // return 1 if queue is empty
int is_queue_full(Queue *q);  // return 1 if queue is full
void print_front_guest(Queue *q);
void print_total_guests_num(Queue *q);
void print_out_error();
int is_exist(Queue *q, char guest_id); // return 1 if guest_id already exists

void display_queue(Queue *q); // display whole queue, for debugging

/* Entry point: main function*/
int main()
{
    Queue *queue = create_queue();

    int input_operation = 0;
    int exit = 0;

    while (!exit)
    {
        // display_queue(queue);

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
    struct Guest *guest = (struct Guest *)malloc(sizeof(struct Guest *));
    guest->guest_id = guest_id;
    guest->num_of_guests = num_of_guests;

    return guest;
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
    if (!is_queue_full(q))
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->guests[q->rear] = guest;
        q->size++;
    }
}

void dequeue(Queue *q)
{
    if (!is_queue_empty(q))
    {
        // struct Guest *deleted_guest = q->guests[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        // free(deleted_guest);
        q->size--;
    }
}

void add_new_guests(Queue *q)
{
    char guest_id;
    int num_of_guests;

    scanf(" %c %d", &guest_id, &num_of_guests);

    if (!is_exist(q, guest_id))
    {
        struct Guest *new_guest = creat_guest(guest_id, num_of_guests);

        enqueue(q, new_guest);
    }
}

void bring_guest_in(Queue *q)
{
    dequeue(q);
}

void print_front_guest(Queue *q)
{
    if (!is_queue_empty(q))
    {
        char front_guest_id = q->guests[(q->front + 1) % MAX_SIZE]->guest_id;
        printf("%c\n", front_guest_id);
    }
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

        for (int i = 1; i < q->size + 1; i++)
        {
            cur_group_guest_num = q->guests[(q->front + i) % MAX_SIZE]->num_of_guests;
            total_num += cur_group_guest_num;
        }

        printf("%d\n", total_num);
    }
}

void print_out_error()
{
    printf("error\n");
}

int is_exist(Queue *q, char guest_id)
{
    if (!is_queue_empty(q))
    {

        // brute force
        for (int i = 1; i < q->size + 1; i++)
        {
            char cmp_guest_id = q->guests[(q->front + i) % MAX_SIZE]->guest_id;
            if (cmp_guest_id == guest_id)
            {
                return 1;
            }
        }
    }
    return 0;
}

void display_queue(Queue *q)
{
    if (!is_queue_empty(q))
    {
        for (int i = 1; i < q->size + 1; i++)
        {
            printf("%c %d ", q->guests[(q->front + i) % MAX_SIZE]->guest_id, q->guests[(q->front + i) % MAX_SIZE]->num_of_guests);
        }
    }
}

/*
Sample input 1 - test basics
1
a 3
1
b 2
1
c 1
1
d 5
2
4
3
2
5
-1

Sample output 1
11
b
8
error
*/

/*
Sample input 2 - test operation3, 4
1
a 3
1
b 3
1
c 3
1
d 3
1
e 3
1
f 3
2
3
4
3
4
3
4
3
4
3
4
3
-1


Sample out 2
15
a
b
c
d
e

*/

/*
Sample input 3 - test invalid
5
10
4
3
-1


Sample output 3
error
error

*/