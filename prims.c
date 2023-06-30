#include <stdio.h>
#include <stdlib.h>


struct Graph {

    int vertices;
    int **adj_matrix;

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

void prims(struct Graph *g,int v,int start) {

    int *visited;

    visited = (int *)malloc (sizeof(int) * v);

    for (int i = 0;i < v;i ++) {

        visited[i] = 0;

    }

    visited[start] = 1;

    int edge = 1;
    printf("%d ",start);

    while (edge < v) {

        int y;int min = 999;

        for (int i = 0;i < v;i ++) {

            if (visited[i]) {

                for (int j = 0;j < v;j ++) {

                    if (!visited[j] && g-> adj_matrix[i][j]) {

                        if (min > g -> adj_matrix[i][j]) {

                            min = g -> adj_matrix[i][j];

                            y = j;

                        }
                    }
                }
            }
        }

        edge ++;
        visited[y] = 1;
        printf("%d ",y);
    }
}

int main() {

    struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));

    int v;
    printf("Enter no.of Vertices : ");
    scanf("%d",&v);

    g = createGraph(v);

    int start;
    printf("Enter Start Index : ");
    scanf("%d",&start);

    prims(g,v,start);

    return 0;
}

