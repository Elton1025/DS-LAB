#include <stdio.h>

int main() {
  int i, j, nodes, max_edges, origin, destin;
  char graph_type;

  printf("Enter the type of graph (d for directed, u for undirected): ");
  scanf(" %c", &graph_type);

  printf("Enter the number of nodes: ");
  scanf("%d", &nodes);

  if (graph_type == 'u' || graph_type == 'U') {
    max_edges = nodes * (nodes - 1) / 2;
  } else {
    max_edges = nodes * (nodes - 1);
  }

  int adj[nodes][nodes];

  for (i = 0; i < nodes; i++) {
    for (j = 0; j < nodes; j++) {
      adj[i][j] = 0;
    }
  }

  for (i = 0; i < max_edges; i++) {
    printf("Enter edge %d (-1 -1 to quit): ", i + 1);
    scanf("%d %d", &origin, &destin);

    if (origin == -1 && destin == -1) {
      break;
    }

    if (origin >= nodes || destin >= nodes || origin < 0 || destin < 0) {
      printf("Invalid edge!\n");
      i--;
    } else {
      adj[origin][destin] = 1;
      if (graph_type == 'u' || graph_type == 'U') {
        adj[destin][origin] = 1;
      }
    }
  }

  printf("The adjacency matrix is:\n");
  for (i = 0; i < nodes; i++) {
    for (j = 0; j < nodes; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }

  return 0;
}
