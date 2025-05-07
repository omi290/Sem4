#include <stdio.h>
#include <stdlib.h>

// Function to reset the visited array
void resetVisitedArray(int visited[], int size) {
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }
}

// Perform Depth First Search
void dfs(int size, int adjMatrix[][size], int current, int visited[]) {
    visited[current] = 1;
    printf("%d --> ", current);

    for (int neighbor = 0; neighbor < size; neighbor++) {
        if (adjMatrix[current][neighbor] == 1 && visited[neighbor] == 0) {
            dfs(size, adjMatrix, neighbor, visited);
        }
    }
}

// Build the adjacency matrix based on user input
void adjacentmatrix(int size, int adjMatrix[][size]) {
    int edges, from, to;

    // Clear the adjacency matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: from to):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &from, &to);

        // Validate ver
        if (from >= 0 && from < size && to >= 0 && to < size) {
            adjMatrix[from][to] = 1; // Edge from->to
            adjMatrix[to][from] = 1; // Undirected graph, so also add to->from
        } else {
            printf("Invalid edge! Please enter valid ver.\n");
            i--; // Reattempt input for invalid edge
        }
    }
}

// Main function
int main() {
    int ver, c, scr;

    // Input the number of ver
    printf("Enter the number of vertex in the graph: ");
    scanf("%d", &ver);

    int graph[ver][ver]; // Adjacency matrix representation
    adjacentmatrix(ver, graph);

    // Menu options
    printf("\nOptions:\n");
    printf("1. Perform DFS (Depth First Search)\n");
    printf("2. Exit\n");

    do {
        printf("\nChoose an option: ");
        scanf("%d", &c);

        switch (c) {
            case 1: {
                int visited[ver]; // Visited array for DFS
                resetVisitedArray(visited, ver);

                // Input the starting node for DFS
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &scr);

                if (scr >= 0 && scr < ver) {
                    printf("DFS Traversal starting from vertex %d: ", scr);
                    dfs(ver, graph, scr, visited);
                    printf("END\n");
                } else {
                    printf("Invalid starting vertex! Try again.\n");
                }
                break;
            }
            case 2:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid option! Please select again.\n");
        }
    } while (c != 2);

    return 0;
}
