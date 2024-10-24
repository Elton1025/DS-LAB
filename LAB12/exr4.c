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

void addEdge(struct Graph* graph, int src, int dest) {
  struct Node* newnode = newNode(dest);
  newnode->next = graph->array[src].head;
  graph->array[src].head = newnode;

  newnode = newNode(src);
  newnode->next = graph->array[dest].head;
  graph->array[dest].head = newnode;
}

void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
  visited[vertex] = 1;
  printf("%d ", vertex);

  struct Node* temp = graph->array[vertex].head;
  while (temp != NULL) {
    int adjVertex = temp->dest;
    if (!visited[adjVertex]) {
      DFSUtil(graph, adjVertex, visited);
    }
    temp = temp->next;
  }
}

void DFS(struct Graph* graph, int startVertex) {
  int visited[graph->V];
  for (int i = 0; i < graph->V; i++) {
    visited[i] = 0;
  }

  DFSUtil(graph, startVertex, visited);
}

int main() {
  int V, i, src, dest, startVertex;

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
      addEdge(graph, src, dest);
    }
  }

  printf("Enter the starting vertex for DFS: ");
  scanf("%d", &startVertex);

  printf("DFS traversal starting from vertex %d: \n", startVertex);
  DFS(graph, startVertex);

  return 0;
}
