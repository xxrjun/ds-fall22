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
void bubble_sort(int *arr, int n);
void quick_sort(int *arr, int n);
void quick_sort_helper(int *arr, int left, int right);
void swap(int *a, int *b);

int main()
{
  int arr[MAX], n;

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
      scanf("%d", &arr[i]);

    /* Print out sorted array */
    for (int i = 0; i < n - 2; i++)
      printf("%d ", arr[i]);

    printf("%d\n", arr[n - 1]);

    /* Call the bubble sort function */
    bubble_sort(arr, n);

    /* Call the quick sort function */
    // quick_sort(arr, n);
  }

  return 0;
}

/**
 * @brief Bubble sort, will print out the execution time of bubble sorting
 *
 * @param arr
 * @param n length or arr
 */
void bubble_sort(int *arr, int n)
{
  /* Start the clock */
  clock_t begin = clock();

  for (int i = 0; i < n - 1; i++)
  {
    if (arr + i > arr + i + 1)
    {
      swap(arr + i, arr + i + 1);
    }
  }

  /* End of clock */
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("bubble sort: %.1f sec", time_spent);
}

void quick_sort(int *arr, int n)
{
  clock_t begin = clock();

  quick_sort_helper(arr, 0, n - 1);

  clock_t end = clock();

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("%.2f", time_spent);
}

/**
 * @brief Quick sort, will print out the execution time of quick sorting
 *
 * @param arr
 * @param left
 * @param right
 */
void quick_sort_helper(int *arr, int left, int right)
{

  /* 比 pivot 大的排左，比 pivot 小的排右*/
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