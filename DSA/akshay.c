#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void dijkstra(int graph[MAX][MAX], int src, int n) {
    int dist[n], parent[n];
    bool visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1)
            break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != -1 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
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
    dijkstra(graph, src, n);
    return 0;
}
