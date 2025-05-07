#include <stdio.h>
#include <limits.h>

#define MAX 100

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void bellmanFord(int graph[MAX][MAX], int src, int n) {
    int dist[n], parent[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int k = 0; k < n - 1; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] != -1 && dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != -1 && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                printf("Negative weight cycle detected\n");
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d : Unreachable\n", i);
        } else {
            printf("%d : %d Path: ", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main() {
    int n, graph[MAX][MAX], src;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = -1;
        }

    scanf("%d", &src);
    bellmanFord(graph, src, n);
    return 0;
}
