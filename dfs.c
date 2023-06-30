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
    int top;
} Stack;

void push(Stack *s, int value) {
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack *s) {
    int item = s->items[s->top];
    s->top--;
    return item;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
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

void dfs(Graph *graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Stack s;
    s.top = -1;

    visited[startVertex] = 1;
    push(&s, startVertex);

    while (!isEmpty(&s)) {
        
        int currentVertex = pop(&s);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                push(&s, i);
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

    printf("DFS traversal: ");
    dfs(graph, startVertex);

    free(graph);

    return 0;
}
