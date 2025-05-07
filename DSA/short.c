#include <stdio.h> 
#include <limits.h> 
 
#define MAX 100 
 
int shortestPathKEdges(int graph[MAX][MAX], int u, int v, int k, int n) { 
    if (k == 0 && u == v) 
        return 0; 
    if (k == 0) 
        return INT_MAX; 
 
    int min = INT_MAX; 
    for (int i = 0; i < n; i++) { 
        if (graph[u][i] != 0) { 
            int rec = shortestPathKEdges(graph, i, v, k - 1, n); 
            if (rec != INT_MAX) 
                if (graph[u][i] + rec < min) 
                    min = graph[u][i] + rec; 
        } 
    } 
    return min; 
} 
 
int main() { 
    int n, graph[MAX][MAX], src, dest, k; 
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &graph[i][j]); 
    scanf("%d %d", &src, &dest); 
    scanf("%d", &k); 
 
    int res = shortestPathKEdges(graph, src - 1, dest - 1, k, n); 
    if (res == INT_MAX) 
        printf("no path of length k is available\n"); 
    else 
        printf("Weight of shortest path from (%d,%d) with %d edges : %d\n", src, dest, k, res); 
    return 0; 
} 