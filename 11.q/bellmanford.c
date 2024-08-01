#include <stdio.h>
#include <limits.h>

// Define the number of vertices in the graph
#define V 6

// Define the structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to initialize the graph with edges
void initializeGraph(struct Edge edges[], int E) {
    edges[0] = (struct Edge){0, 1, 6};
    edges[1] = (struct Edge){0, 2, -3};
    edges[2] = (struct Edge){1, 3, -4};
    edges[3] = (struct Edge){1, 4, -1};
    edges[4] = (struct Edge){2, 1, 8};
    edges[5] = (struct Edge){3, 4, 4};
    edges[6] = (struct Edge){3, 5, 2};
    edges[7] = (struct Edge){4, 2, -2};
    edges[8] = (struct Edge){4, 5, 3};
    edges[9] = (struct Edge){5, 0, 3};
}

// Function to print the solution
void printSolution(int dist[]) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d\t%d\n", i, dist[i]);
}

// Bellman-Ford algorithm
void BellmanFord(struct Edge edges[], int E, int src) {
    int dist[V];

    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printSolution(dist);
}

int main() {
    int E = 10;  // Number of edges in the graph
    struct Edge edges[E];

    initializeGraph(edges, E);

    BellmanFord(edges, E, 0);

    return 0;
}
