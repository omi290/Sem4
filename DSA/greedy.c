#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 100 
 
typedef struct { 
    int u, v, weight; 
} Edge; 
 
Edge edges[MAX * MAX]; 
int parent[MAX]; 
 
int find(int u) { 
    if (parent[u] == u) 
        return u; 
    return parent[u] = find(parent[u]); 
} 
 
void unionSet(int u, int v) { 
    int pu = find(u); 
    int pv = find(v); 
    parent[pu] = pv; 
} 
int compare(const void* a, const void* b) { 
    Edge* e1 = (Edge*)a; 
    Edge* e2 = (Edge*)b; 
    return e2->weight - e1->weight; 
} 
 
int main() { 
    int V; 
    scanf("%d", &V); 
 
    int adj[MAX][MAX]; 
    int edgeCount = 0; 
 
    for (int i = 0; i < V; i++) { 
        for (int j = 0; j < V; j++) { 
            scanf("%d", &adj[i][j]); 
            if (i < j && adj[i][j] > 0) { 
                edges[edgeCount].u = i; 

                edges[edgeCount].v = j; 
                edges[edgeCount].weight = adj[i][j]; 
                edgeCount++; 
            } 
        } 
    } 
 
   
    for (int i = 0; i < V; i++) 
        parent[i] = i; 
 
    qsort(edges, edgeCount, sizeof(Edge), compare); 
 
    int maxWeight = 0; 
    int selectedEdges = 0; 
 
    
    for (int i = 0; i < edgeCount && selectedEdges < V - 1; i++) { 
        int u = edges[i].u; 
        int v = edges[i].v; 
        int w = edges[i].weight; 
 
        if (find(u) != find(v)) { 
            unionSet(u, v); 
            maxWeight += w; 
            selectedEdges++; 
        } 
    } 
 
    printf("Maximum Spanning Weight: %d\n", maxWeight); 
    return 0; 
} 