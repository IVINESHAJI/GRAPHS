#include <stdio.h>
#include <stdlib.h>

struct Edges {
    int source;
    int dest;
    int weight;
};

struct Graph {
    int vertices;
    struct Edges* E;
};

struct Graph* createGraph(int v, int e) {
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->vertices = v;
    g->E = (struct Edges*)malloc(sizeof(struct Edges) * e);

    for (int i = 0; i < e; i++) {
        printf("Enter Source for Edge: ");
        scanf("%d", &(g->E[i].source));

        printf("Enter Destination for Edge: ");
        scanf("%d", &(g->E[i].dest));

        printf("Enter Weight for Edge: ");
        scanf("%d", &(g->E[i].weight));
    }

    return g;
}

void swapEdges(struct Edges* a, struct Edges* b) {
    struct Edges temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct Edges E[], int e) {

    for (int i = 0; i < e - 1; i++) {

        for (int j = 0; j < e - i - 1; j++) {

            if (E[j].weight > E[j + 1].weight) {

                swapEdges(&E[j], &E[j + 1]);
            }
        }
    }
}

int findParent(int v, int parent[]) {

    if (parent[v] == v) {

        return v;
    }

    return findParent(parent[v], parent);
}

void Kruskals(struct Graph* g, int v, int e) {
    // Sort the edges based on weight
    sort(g->E, e);

    // Create an output array of edges
    struct Edges* kruskal = (struct Edges*)malloc((v - 1) * sizeof(struct Edges));

    int parent[v];

    for (int i = 0; i < v; i++) {
        parent[i] = i; // Initialize parent array
    }

    int count = 0; // For no. of edges
    int i = 0;     // Iterator for traversing through input array

    while (count != v - 1) {

        struct Edges currentEdge = g->E[i]; // A temporary Edge chosen

        // Check if we can add the currentEdge in MST or not
        // For that, we check the parent
        // If the parent is itself, we will visit; otherwise, ignore it

        int sourceParent = findParent(g->E[i].source, parent); // FIND FUNCTION is implemented
        int destParent = findParent(g->E[i].dest, parent);     // FIND FUNCTION is implemented

        if (sourceParent != destParent) {

            kruskal[count] = currentEdge; 
            count++;

            parent[sourceParent] = destParent; // UNION is used
        }
        i++;
    }

    for (int i = 0; i < v - 1; i++) {
        if (kruskal[i].source > kruskal[i].dest) {
            printf("%d - %d\n", kruskal[i].source, kruskal[i].dest);
        } else {
            printf("%d - %d\n", kruskal[i].dest, kruskal[i].source);
        }
    }

    free(kruskal);
}

int main() {
    int v, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    struct Graph* g = createGraph(v, e);

    Kruskals(g, v, e);

    free(g->E);
    free(g);

    return 0;
}
