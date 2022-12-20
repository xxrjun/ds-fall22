/**
 * @file 109403019_hw4_algo.c
 * @author MIS 109403019 鄒翔宇
 * @brief
 * @version 0.1
 * @date 2022-12-16
 *
 * @copyright Copyright (c) 2022
 *
 */

// Using adjacency matrix to represent a graph, and using Kruskal's algorithm and Prim's algorithm to find the minimum spanning tree of the graph.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

/* Declaration of functions */
void kruskal(int n, int graph[MAX][MAX]);
void prim(int n, int graph[MAX][MAX]);
int find(int *parent, int i);
void union_set(int *parent, int x, int y);
int min_key(int *key, int *mst_set, int n);
void print_mst(int *parent, int n, int graph[MAX][MAX]);

int main()
{
  int n;
  int graph[MAX][MAX];

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
  kruskal(n, graph);
  prim(n, graph);

  return 0;
}

// Using Kruskal's algorithm to find the minimum spanning tree of the graph.
void kruskal(int n, int graph[MAX][MAX])
{
  int parent[n];
  int edge_count = 0;
  int min_cost = 0;
  int min, min_i, min_j;

  /* Initialize parent array */
  for (int i = 0; i < n; i++)
    parent[i] = i;

  /* Find the minimum spanning tree of the graph */
  while (edge_count < n - 1)
  {
    min = 999999;

    /* Find the minimum weight edge */
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (graph[i][j] < min)
        {
          min = graph[i][j];
          min_i = i;
          min_j = j;
        }
      }
    }

    /* Check if the edge is a cycle */
    if (find(parent, min_i) != find(parent, min_j))
    {
      printf("%d %d\n", min_i, min_j);
      edge_count++;
      min_cost += min;
      union_set(parent, min_i, min_j);
    }

    /* Set the weight of the edge to 999999 to avoid finding the same edge again */
    graph[min_i][min_j] = 999999;
    graph[min_j][min_i] = 999999;
  }

  printf("%d\n", min_cost);
}

// Using Prim's algorithm to find the minimum spanning tree of the graph.
void prim(int n, int graph[MAX][MAX])
{
  int parent[n];
  int key[n];
  int mst_set[n];
  int min_cost = 0;

  /* Initialize parent array, key array, and mst_set array */
  for (int i = 0; i < n; i++)
  {
    key[i] = 999999;
    mst_set[i] = 0;
  }

  /* Set the first vertex as the root of the tree */
  key[0] = 0;
  parent[0] = -1;

  /* Find the minimum spanning tree of the graph */
  for (int i = 0; i < n - 1; i++)
  {
    /* Find the minimum key vertex */
    int u = min_key(key, mst_set, n);

    /* Add the vertex to the mst_set */
    mst_set[u] = 1;

    /* Update the key value of the adjacent vertices of the vertex */
    for (int v = 0; v < n; v++)
    {
      if (graph[u][v] && mst_set[v] == 0 && graph[u][v] < key[v])
      {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }

  /* Print the minimum spanning tree */
  print_mst(parent, n, graph);
}

// Find the root of the set
int find(int *parent, int i)
{
  if (parent[i] == -1)
    return i;
  return find(parent, parent[i]);
}

// Union two sets
void union_set(int *parent, int x, int y)
{
  int xset = find(parent, x);
  int yset = find(parent, y);
  parent[xset] = yset;
}

// Find the minimum key vertex
int min_key(int *key, int *mst_set, int n)
{
  int min = 999999;
  int min_index;

  for (int i = 0; i < n; i++)
  {
    if (mst_set[i] == 0 && key[i] < min)
    {
      min = key[i];
      min_index = i;
    }
  }

  return min_index;
}

// Print the minimum spanning tree
void print_mst(int *parent, int n, int graph[MAX][MAX])
{
  int min_cost = 0;

  for (int i = 1; i < n; i++)
  {
    printf("%d %d", parent[i], i);

    /* Calculate the minimum cost */
    min_cost += graph[i][parent[i]];
  }

  printf("%d", min_cost);
}