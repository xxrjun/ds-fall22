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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// kruskal's algorithm
typedef struct edge
{
  int u, v, w;
} edge;

typedef struct graph
{
  int n, m;
  edge *edges;
} graph;

typedef struct subset
{
  int parent, rank;
} subset;

int cmp(const void *a, const void *b)
{
  edge *x = (edge *)a, *y = (edge *)b;
  return x->w - y->w;
}

int find(subset *subsets, int i)
{
  if (subsets[i].parent != i)
  {
    subsets[i].parent = find(subsets, subsets[i].parent);
  }
  return subsets[i].parent;
}

void Union(subset *subsets, int x, int y)
{
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);

  if (subsets[xroot].rank < subsets[yroot].rank)
  {
    subsets[xroot].parent = yroot;
  }
  else if (subsets[xroot].rank > subsets[yroot].rank)
  {
    subsets[yroot].parent = xroot;
  }
  else
  {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

void kruskal(graph *g)
{
  int e = 0, i = 0;
  edge result[g->n];
  qsort(g->edges, g->m, sizeof(g->edges[0]), cmp);
  subset *subsets = (subset *)malloc(g->n * sizeof(subset));
  for (int v = 0; v < g->n; v++)
  {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }
  while (e < g->n - 1 && i < g->m)
  {
    edge next_edge = g->edges[i++];
    int x = find(subsets, next_edge.u);
    int y = find(subsets, next_edge.v);
    if (x != y)
    {
      result[e++] = next_edge;
      Union(subsets, x, y);
    }
  }
  for (i = 0; i < e; i++)
  {
    printf("%d %d %d", result[i].u, result[i].v, result[i].w);
  }
}

int main()
{
  int n = 0;
  int m = 0;

  graph *g = (graph *)malloc(sizeof(graph));

  while (n != -1)
  {
    scanf("%d", &n);
    if (n == -1)
    {
      break;
    }
    scanf("%d", &m);

    g->n = n;
    g->m = m;
    g->edges = (edge *)malloc(m * sizeof(edge));
    for (int i = 0; i < m; i++)
    {
      scanf("%d %d %d", &g->edges[i].u, &g->edges[i].v, &g->edges[i].w);
    }
    kruskal(g);
  }

  for (int i = 0; i < m; i++)
  {
    scanf("%d %d %d", &g->edges[i].u, &g->edges[i].v, &g->edges[i].w);
  }
  kruskal(g);
  return 0;
}
