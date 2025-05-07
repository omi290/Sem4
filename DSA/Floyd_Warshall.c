#include <stdio.h>
#include <limits.h>

#define INF 9999999

int main() {
    int V;
    scanf("%d", &V);

    int graph[V][V];
    int dist[V][V];

  
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            char input[10];
            scanf("%s", input);
            if (input[0] == 'I')
                graph[i][j] = INF;
            else
                sscanf(input, "%d", &graph[i][j]);
        }
    }

   
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("Shortest Distance Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
