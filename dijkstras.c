#include <stdio.h>
#include <stdlib.h>


struct Graph {
    int vertices;
    int **adj_matrix ;
};

struct Graph *createGraph(int vertices) {

    struct  Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
    g -> vertices = vertices;

    g -> adj_matrix = (int **)malloc(vertices * sizeof(int *));

    for (int i = 0;i < vertices;i ++) {

        g -> adj_matrix[i] = (int *)malloc(vertices * sizeof(int ));

    } 

    for (int i = 0;i < vertices;i ++) {

        for (int j = 0 ;j < vertices;j ++) {

            g -> adj_matrix[i][j] = 0;

        }
    }

    int ans;
    for (int i = 0;i < vertices;i ++) {

        for (int j = 0 ;j < vertices;j ++) {

            printf("Is there edge between %d and %d (Enter weight):",i,j);
            scanf("%d",&ans);
            g -> adj_matrix[i][j] = ans;

        }
    }



    return g;
    
}

int findMinVertex(int distance[],int visited[],int v) {

    int minVertex = -1;

    for(int i = 0;i < v;i ++) { // To check min weight edged dest

        //Checks if node is visited and if dist of i is less than dist of minVertex
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) { 

            minVertex = i; //updated the minVertex
             
        }
    }

    return minVertex;
}

void Dijkstras(struct Graph *g,int v) {

    int distance[v];

    int visited[v];

    for(int i = 0;i < v;i ++) {

        visited[i] = 0;
        distance[i] = 9999;

    }

    distance[0] = 0;// Source vertex distance set to zero

    for(int i = 0;i < v - 1;i ++) { // Run till v - 1 to form v - 1 edges

        int minVertex = findMinVertex(distance,visited,v);

        visited[minVertex] = 1;// Updated the visited array

        //After Node is selected we calculate dist and update the distance array 
        for (int j = 0;j < v;j ++) {

            if (g -> adj_matrix[minVertex][j] && !visited[j]) {
                
                //1. Vertex is selected only if it has a edge
                //2. Calculate the distance from the vertex

                int dist = distance[minVertex] + g -> adj_matrix[minVertex][j]; 

                // 3. Distance is updated for the selected vertex to connected vertices
                if (dist < distance[j] ) {

                    distance[j] = dist;

                }
            }
        }
    }

    for (int i = 0;i < v;i ++) {

        printf("Vertex - %d and weight - %d\n",i,distance[i]);

    }

}

int main() {
    int v, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    struct Graph* g = createGraph(v);

    Dijkstras(g, v);

    return 0;

}