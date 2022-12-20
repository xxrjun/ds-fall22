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

#define MAX 100000

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
    for (int j = 0; j < n - 1 - i; j++)
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

  quick_sort_helper(arr, 0, n - 1);

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
    int pivot = left;

    /* Put values larger than pivot_val to right, smaller to left. */
    while (i != j)
    {
      /* From right first */
      while (arr[j] > arr[pivot] && i < j)
        j--;

      /* From left */
      while (arr[i] <= arr[pivot] && i < j)
        i++;

      /* Swap two elements */
      swap(&arr[i], &arr[j]);
    }

    /* Swap i with pivot */
    swap(&arr[pivot], &arr[j]);

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
