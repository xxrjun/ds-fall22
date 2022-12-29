/**
 * @file 109403019_hw4_algo.c
 * @author MIS 109403019 鄒翔宇
 * @brief
 * @version 0.1
 * @date 2022-12-28
 *
 * @copyright Copyright (c) 2022
 *
 */

// Using adjacency matrix to represent a graph, and using Kruskal's algorithm and Prim's algorithm to find the minimum spanning tree of the graph.
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define MAX_INT 999999

/* Declaration of functions */
int prim(int n, int graph[MAX][MAX]);
int kruskal(int n, int graph[MAX][MAX]);

int main()
{
  int n = 0;
  int graph[MAX][MAX]; // Adjacency matrix
  int min_cost_kruskal, min_cost_prim;

  while (n != -1)
  {
    /* Input the number of vertices */
    scanf("%d", &n);

    /* Input the adjacency matrix */
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        scanf("%d", &graph[i][j]);
      }
    }

    /* Find the minimum spanning tree of the graph */
    min_cost_prim = prim(n, graph);
    // min_cost_kruskal = kruskal(n, graph);

    printf("Prim minimum cost: %d\n", min_cost_prim);
    // printf("Kruskal minimum cost: %d", min_cost_kruskal);
  }

  return 0;
}

int prim(int n, int graph[MAX][MAX])
{
  int min_cost = 0;
  int visited[MAX] = {0};
  int min_edge[MAX] = {0};
  int min_cost_edge[MAX] = {0};
  int min_cost_vertex = 0;

  visited[0] = 1;
  for (int i = 1; i < n; i++)
  {
    min_edge[i] = 0;
    min_cost_edge[i] = graph[0][i];
  }

  for (int i = 1; i < n; i++)
  {
    int min = MAX_INT;
    for (int j = 1; j < n; j++)
    {
      if (visited[j] == 0 && min_cost_edge[j] < min)
      {
        min = min_cost_edge[j];
        min_cost_vertex = j;
      }
    }

    visited[min_cost_vertex] = 1;
    min_cost += min_cost_edge[min_cost_vertex];
    for (int j = 1; j < n; j++)
    {
      if (visited[j] == 0 && graph[min_cost_vertex][j] < min_cost_edge[j])
      {
        min_cost_edge[j] = graph[min_cost_vertex][j];
        min_edge[j] = min_cost_vertex;
      }
    }
  }

  return min_cost;
}