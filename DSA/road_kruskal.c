#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 100 
 
struct Edge { 
    int src, dest, weight; 
}; 
 
struct Subset { 
    int parent, rank; 
}; 
 
int find(struct Subset subsets[], int i) { 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
    return subsets[i].parent; 
} 
 
void Union(struct Subset subsets[], int x, int y) { 
    int xroot = find(subsets, x), yroot = find(subsets, y); 
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
    else { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 

    } 
} 
 
int compare(const void *a, const void *b) { 
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight; 
} 
 
void kruskalMST(int graph[MAX][MAX], int V) { 
    struct Edge edges[V * V]; 
    int e = 0; 
 
    for (int i = 0; i < V; i++) 
        for (int j = i + 1; j < V; j++) 
            if (graph[i][j]) { 
                edges[e].src = i; 
                edges[e].dest = j; 
                edges[e].weight = graph[i][j]; 
                e++; 
            } 
 
    qsort(edges, e, sizeof(edges[0]), compare); 
 
    struct Subset subsets[V]; 
    for (int v = 0; v < V; v++) { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    } 
 
    int result = 0, count = 0, i = 0; 

    while (count < V - 1 && i < e) { 
        struct Edge next = edges[i++]; 
        int x = find(subsets, next.src); 
        int y = find(subsets, next.dest); 
        if (x != y) { 
            result += next.weight; 
            Union(subsets, x, y); 
            count++; 
        } 
    } 
 
    printf("Minimum Spanning Weight: %d\n", result); 
} 
 
int main() { 
    int V, graph[MAX][MAX]; 
    scanf("%d", &V); 
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            scanf("%d", &graph[i][j]); 
    kruskalMST(graph, V); 
    return 0; 
} 