#include <stdio.h>
#include <stdlib.h>

struct Node {

    int vertex;
    struct Node *next;
 
};

struct Graph {/*Grapgh data structure with no.of vertices and adjacency list*/

    int vertices;
    struct Node ** adjlist;

};

struct Node *createNode(int v) {/*To create a node*/

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> next = NULL;
    newNode -> vertex = v;

    return newNode;
}

struct Graph * createGraph(int vertices) {/* Creating a graph */

    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));/* Creating a graph */
    graph -> vertices = vertices;

    graph -> adjlist = (struct Node **)malloc(vertices * sizeof(struct Node *));/* Creating an adjacency list */

    for (int i = 0 ;i < vertices;i ++) {
        graph -> adjlist[i] = NULL;/* Initially mking all the elements NULL */
    }

    return graph;
}

void addEdge (struct Graph *graph,int src,int dest) {/*For directed graph.*/

    struct Node *newNode = createNode(dest);

    newNode -> next = graph -> adjlist[src];
    graph -> adjlist[src] = newNode;
 

    newNode = createNode(src);                  /* For undirected graph */
    newNode -> next = graph -> adjlist[dest]; 
    graph -> adjlist[dest] = newNode;

    
}

void printGraph(struct Graph* g) {

    for (int v = 0; v < g -> vertices;v ++) {

        struct Node  *temp = (struct Node *)malloc(sizeof(struct Node));
        temp = g -> adjlist[v];
        printf("Adjacency Vertex of %d : ",v);

        while (temp) {

            printf("%d\t",temp -> vertex);
            temp = temp -> next;

        }
        printf("\n");

    }

}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
