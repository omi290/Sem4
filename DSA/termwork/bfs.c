#include<stdio.h>
#include<stdlib.h>

// Function to initialize the visited array
void visitedarray(int visited[], int size) {
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }
}

// Breadth First Search (BFS) function
void bfs(int size, int adjMatrix[][size], int startVertex) {
    int visited[size];
    int queue[size], front = 0, rear = 0;

    visitedarray(visited, size);
    printf("BFS Traversal starting from vertex %d:\n", startVertex);

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d --> ", currentVertex);

        for (int i = 0; i < size; i++) {
            if (adjMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("END\n");
}

// Function to input the adjacency matrix of the graph
void buildGraph(int size, int adjMatrix[][size]) {
    int edges, from, to;

    // Initialize all edges to 0
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
        if (from >= 0 && from < size && to >= 0 && to < size) {
            adjMatrix[from][to] = 1; // Mark edge from -> to
            adjMatrix[to][from] = 1; // Mark edge to -> from for undirected graph
        } else {
            printf("Invalid edge! Please re-enter.\n");
            i--; // Retry invalid edge input
        }
    }
}

// Main function
int main() {
    int vertices, choice, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[vertices][vertices]; // Adjacency matrix representation
    buildGraph(vertices, graph);

    printf("\nMenu:\n");
    printf("1. Perform BFS (Breadth First Search)\n");
    printf("2. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &startVertex);

                if (startVertex >= 0 && startVertex < vertices) {
                    bfs(vertices, graph, startVertex);
                } else {
                    printf("Invalid starting vertex! Try again.\n");
                }
                break;
            }

            case 2:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 2);

    return 0;
}
