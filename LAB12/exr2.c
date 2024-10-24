#include <stdio.h>
#include <stdlib.h>

struct Node {
  int dest;
  struct Node* next;
};

struct AdjList {
  struct Node *head;
};

struct Graph {
  int V;
  struct AdjList* array;
};

struct Node* newNode(int dest) {
  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->dest = dest;
  newnode->next = NULL;
  return newnode;
}

struct Graph* createGraph(int V) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
  int i;
  for (i = 0; i < V; ++i) {
    graph->array[i].head = NULL;
  }
  return graph;
}

void addEdge(struct Graph* graph, int src, int dest, char graph_type) {
  struct Node* newnode = newNode(dest);
  newnode->next = graph->array[src].head;
  graph->array[src].head = newnode;

  if (graph_type == 'u' || graph_type == 'U') {
    newnode = newNode(src);
    newnode->next = graph->array[dest].head;
    graph->array[dest].head = newnode;
  }
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->V; ++v) {
    struct Node* pCrawl = graph->array[v].head;
    printf("\n Adjacency list of vertex %d\n head ", v);
    while (pCrawl) {
      printf("-> %d", pCrawl->dest);
      pCrawl = pCrawl->next;
    }
    printf("\n");
  }
}

int main() {
  int V, i, src, dest;
  char graph_type;

  printf("Enter the type of graph (d for directed, u for undirected): ");
  scanf(" %c", &graph_type);

  printf("Enter the number of vertices: ");
  scanf("%d", &V);

  struct Graph* graph = createGraph(V);

  for (i = 0; i < V * V; i++) {
    printf("Enter edge %d (-1 -1 to quit): ", i + 1);
    scanf("%d %d", &src, &dest);

    if (src == -1 && dest == -1) {
      break;
    }

    if (src >= V || dest >= V || src < 0 || dest < 0) {
      printf("Invalid edge!\n");
      i--;
    } else {
      addEdge(graph, src, dest, graph_type);
    }
  }

  printGraph(graph);

  return 0;
}
