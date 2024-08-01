#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 5  // Number of locations

int findMinCost(int graph[N][N], int start) {
    bool visited[N] = { false };
    int minCost = 0;
    int u = start;

    for (int count = 0; count < N - 1; count++) {
        visited[u] = true;
        int next = -1;
        int minDist = INT_MAX;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] < minDist) {
                minDist = graph[u][v];
                next = v;
            }
        }

        if (next == -1) {
            // If there is no next node to visit, we can't complete the cycle
            printf("Graph is not fully connected\n");
            return INT_MAX;
        }

        minCost += minDist;
        u = next;
    }

    // Return to start to complete the cycle
    if (graph[u][start] == INT_MAX) {
        printf("No return path to starting point\n");
        return INT_MAX;
    }
    
    minCost += graph[u][start];
    return minCost;
}

int main() {
    int graph[N][N] = {
        { 0, 2, INT_MAX, 12, 5 },
        { 2, 0, 4, 8, INT_MAX },
        { INT_MAX, 4, 0, 3, INT_MAX },
        { 12, 8, 3, 0, 10 },
        { 5, INT_MAX, INT_MAX, 3, 0 }
    };

    int startLocation = 0;
    int minCost = findMinCost(graph, startLocation);

    if (minCost == INT_MAX) {
        printf("Unable to find a complete cycle starting from location %d\n", startLocation + 1);
    } else {
        printf("Minimum cost starting from location %d is %d\n", startLocation + 1, minCost);
    }

    return 0;
}
