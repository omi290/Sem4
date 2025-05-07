#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
bool isBipartite(int graph[MAX][MAX], int n) {
    int color[MAX];
    memset(color, -1, sizeof(color));

    for (int start = 0; start < n; start++) {
        if (color[start] == -1) {
            color[start] = 0;

            int queue[MAX], front = 0, rear = 0;
            queue[rear++] = start;

            while (front < rear) {
                int u = queue[front++];

                for (int v = 0; v < n; v++) {
                    if (graph[u][v] == 1 && color[v] == -1) {
                        color[v] = 1 - color[u];
                        queue[rear++] = v;
                    } else if (graph[u][v] == 1 && color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (isBipartite(graph, n)) {
        printf("Yes Bipartite\n");
    } else {
        printf("Not Bipartite\n");
    }

    return 0;
}
