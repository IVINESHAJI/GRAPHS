#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, int value) {
    q->items[q->rear] = value;
    q->rear++;
}

int dequeue(Queue *q) {
    int item = q->items[q->front];
    q->front++;
    return item;
}

bool isEmpty(Queue *q) {

    return q->front == q->rear;

}

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    int ans;

    for (int i = 0; i < vertices; i++) {

        for (int j = 0; j < vertices; j++) {

            printf("Is there a connection between %d and %d? (1 for yes, 0 for no): ", i, j);
            scanf("%d", &ans);
            graph->adjMatrix[i][j] = ans;
            
        }
    }

    return graph;
}

void bfs(Graph *graph, int startVertex) {

    int visited[MAX_VERTICES] = {0};
    Queue q;
    q.front = 0;
    q.rear = 0;

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {

                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }

    printf("\n");
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph *graph = createGraph(vertices);

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS traversal: ");
    bfs(graph, startVertex);

    free(graph);

    return 0;
}
