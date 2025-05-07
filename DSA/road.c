#include <stdio.h> 
#include <limits.h> 
#include <stdbool.h> 
 
#define MAX 100 
 
int minKey(int key[], bool mstSet[], int V) { 
    int min = INT_MAX, min_index; 
    for (int v = 0; v < V; v++) 
        if (!mstSet[v] && key[v] < min) 
            min = key[v], min_index = v; 
    return min_index; 
} 
 
void primMST(int graph[MAX][MAX], int V) { 
    int parent[V], key[V]; 
    bool mstSet[V]; 
    for (int i = 0; i < V; i++) 

        key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0; 
    parent[0] = -1; 
 
    for (int count = 0; count < V - 1; count++) { 
        int u = minKey(key, mstSet, V); 
        mstSet[u] = true; 
 
        for (int v = 0; v < V; v++) 
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
 
    int total = 0; 
    for (int i = 1; i < V; i++) 
        total += graph[i][parent[i]]; 
    printf("Minimum Spanning Weight: %d\n", total); 
} 
 
int main() { 
    int V, graph[MAX][MAX]; 
    scanf("%d", &V); 
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            scanf("%d", &graph[i][j]); 
    primMST(graph, V); 
    return 0; 
} 