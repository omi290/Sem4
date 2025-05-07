#include <stdio.h>
#include <stdbool.h>

#define MAX 100
bool dfsCycle(int graph[MAX][MAX], int node, bool visited[], bool recStack[], int n) {
    if (!visited[node]) {
        visited[node] = true;
        recStack[node] = true;
        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (graph[node][neighbor] == 1) { 
                if (!visited[neighbor] && dfsCycle(graph, neighbor, visited, recStack, n)) {
                    return true; 
                } 
                else if (recStack[neighbor]) {
                    return true; 
                }
            }
        }
    }


    recStack[node] = false;
    return false;
}

bool hasCycle(int graph[MAX][MAX], int n) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfsCycle(graph, i, visited, recStack, n)) {
            return true; 
        }
    }
    return false; 
}

int main() {
    int n, graph[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (hasCycle(graph, n)) {
        printf("Yes Cycle Exists\n");
    } 
    else {
        printf("No Cycle Exists\n");
    }

    return 0;
}
