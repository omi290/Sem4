#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void DFS(int graph[MAX][MAX], int visited[], int n, int current) {
    visited[current] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            DFS(graph, visited, n, i);
        }
    }
}


int isPathExist(int graph[MAX][MAX], int n, int src, int dest) {
    int visited[MAX] = {0};
    DFS(graph, visited, n, src);
    return visited[dest];
}

int main() {
    int n, src, dest;
    int graph[MAX][MAX];

    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source and destination vertices (1-based index): ");
    scanf("%d %d", &src, &dest);


    src -= 1;
    dest -= 1;

   
    if (isPathExist(graph, n, src, dest)) {
        printf("Yes Path Exists\n");
    } else {
        printf("No Such Path Exists\n");
    }
    return 0;
}