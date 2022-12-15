/**
 * @file 109403019_hw4_sorting.c
 * @author MIS3A 109403019 鄒翔宇
 * @brief
 * @version 0.1
 * @date 2022-12-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <time.h>

#define MAX 100

/* Declaration of functions */
double bubble_sort(int *arr, int n);
double quick_sort(int *arr, int n);
void quick_sort_helper(int *arr, int left, int right);
void swap(int *a, int *b);

int main()
{
  int arr[MAX];
  int copy_arr[MAX];
  int n = 0;

  while (n != -1)
  {
    /* Input the number of elements */
    scanf("%d", &n);

    if (n == -1)
    {
      break;
    }

    /* Input the elements */
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }

    // /* Copy array */
    for (int i = 0; i < n; i++)
      copy_arr[i] = arr[i];

    /* Get the execution time */
    double time_bubble_sort = bubble_sort(arr, n);
    double time_quick_sort = quick_sort(copy_arr, n);

    /* Print out sorted array and execution time of two sorting method */
    for (int i = 0; i < n - 1; i++)
      printf("%d ", arr[i]);
    printf("%d\n", arr[n - 1]);

    printf("bubble sort : %.1f sec\n", time_bubble_sort);
    printf("quick sort : %.1f sec\n", time_quick_sort);
  }

  return 0;
}

/**
 * @brief Bubble sort, will print out the execution time of bubble sorting
 *
 * @param arr
 * @param n length or arr
 *
 * @return int time of execution
 */
double bubble_sort(int *arr, int n)
{
  /* Start the clock */
  clock_t begin = clock();

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {
      if (*(arr + j) > *(arr + j + 1))
      {
        swap(arr + j, arr + j + 1);
      }
    }
  }

  /* End of clock */
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  return time_spent;
}

/**
 * @brief Quick sort, will print out the execution time of quick sorting
 *
 * @param arr
 * @param n
 * @return int time of execution
 */
double quick_sort(int *arr, int n)
{
  clock_t begin = clock();

  // quick_sort_helper(arr, 0, n - 1);

  clock_t end = clock();

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  return time_spent;
}

void quick_sort_helper(int *arr, int left, int right)
{
  if (left < right)
  {
    int i = left;
    int j = right;

    int pivot_val = arr[left];

    /* Put values larger than pivot_val to right, smaller to left. */
    while (i != j)
    {
      /* From right first */
      while (arr[j] > pivot_val && i < j)
        j--;

      /* From left */
      while (arr[i] <= pivot_val && i < j)
        i++;

      /* Swap two elements */
      swap(&arr[i], &arr[j]);
    }

    /* Swap with pivot */
    swap(&arr[j], &arr[i]);

    /* sort left site */
    quick_sort_helper(arr, left, i - 1);

    /* sort right site */
    quick_sort_helper(arr, i + 1, right);
  }
}

/**
 * @brief Swapping
 *
 * @param a
 * @param b
 */
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* Test Case*/
/*

Test Case 1
5
5 1 3 4 2
1 2 3 4 5
10
1 3 7 2 4 8 9 10 6 5


----------------------

Test Case 2
100
30 96 84 61 53 91 29 16 8 72 86 99 58 68 69 49 65 87 38 12 62 17 40 5 35 23 37 33 90 63 41 88 25 42 20 31 22 81 66 45 9 55 76 14 60 50 47 56 85 15 89 71 59 24 21 77 95 34 80 48 32 100 3 79 74 46 52 57 28 44 82 13 2 36 92 43 26 83 98 7 6 54 70 39 27 64 93 73 1 18 4 67 94 10 51 78 75 11 97 19

*/