#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // For INT_MAX

#define MAX_NODES 5

// Adjacency matrix representing the directed weighted graph
int graph[MAX_NODES][MAX_NODES] = {
    {0, 20, 30, 10, 0},
    {0, 0, 40, 0, 0},
    {0, 0, 0, 10, 20},
    {0, 0, 5, 0, 80},
    {0, 0, 10, 0, 0},
};

void DFS(int node, bool visited[]) {
    visited[node] = true;
    printf("%d ", node + 1); // +1 to match the node numbering in the diagram

    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[node][i] != 0 && !visited[i]) {
            DFS(i, visited);
        }
    }
}

int main() {
    int source = 0; // Source node (starting node)
    bool visited[MAX_NODES] = {false}; // Initialize all nodes as not visited

    printf("Nodes reachable from node %d are: ", source + 1); // +1 to match the node numbering in the diagram
    DFS(source, visited);
    printf("\n");

    return 0;
}
