#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Edge {
    char dest;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int numNodes;
    Edge* adjList[100];
    char nodeIds[100];
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = 0;
    memset(graph->adjList, 0, sizeof(graph->adjList));
    memset(graph->nodeIds, 0, sizeof(graph->nodeIds));
    return graph;
}

void addNode(Graph* graph, int index, char id) {
    graph->nodeIds[index] = id;
    graph->numNodes++;
}

void addEdges(Graph* graph, char src, int numEdges, char* dests, int* weights) {
    int srcIndex = strchr(graph->nodeIds, src) - graph->nodeIds;

    for (int i = 0; i < numEdges; i++) {
        char dest = dests[i];
        int weight = weights[i];

        Edge* newEdge = (Edge*)malloc(sizeof(Edge));
        newEdge->dest = dest;
        newEdge->weight = weight;
        newEdge->next = graph->adjList[srcIndex];
        graph->adjList[srcIndex] = newEdge;

        int destIndex = strchr(graph->nodeIds, dest) - graph->nodeIds;
        newEdge = (Edge*)malloc(sizeof(Edge));
        newEdge->dest = src;
        newEdge->weight = weight;
        newEdge->next = graph->adjList[destIndex];
        graph->adjList[destIndex] = newEdge;
    }
}

int getNodeIndex(Graph* graph, char id) {
    char* pos = strchr(graph->nodeIds, id);
    return pos ? (pos - graph->nodeIds) : -1;
}

int minDistance(int dist[], int visited[], int numNodes) {
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < numNodes; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(Graph* graph, char src, char dest) {
    int srcIndex = getNodeIndex(graph, src);
    int destIndex = getNodeIndex(graph, dest);

    if (srcIndex == -1 || destIndex == -1) {
        printf("Invalid start or end node.\n");
        return;
    }

    int dist[100], prev[100], visited[100];
    for (int i = 0; i < graph->numNodes; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = 0;
    }
    dist[srcIndex] = 0;

    for (int i = 0; i < graph->numNodes - 1; i++) {
        int u = minDistance(dist, visited, graph->numNodes);
        if (u == -1) break;
        visited[u] = 1;

        Edge* edge = graph->adjList[u];
        while (edge) {
            int v = getNodeIndex(graph, edge->dest);
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + edge->weight < dist[v]) {
                dist[v] = dist[u] + edge->weight;
                prev[v] = u;
            }
            edge = edge->next;
        }
    }

    if (dist[destIndex] == INT_MAX) {
        printf("No path found from %c to %c.\n", src, dest);
    } else {
        printf("Shortest path: ");
        int node = destIndex;
        char path[100];
        int pathLen = 0;
        while (node != -1) {
            path[pathLen++] = graph->nodeIds[node];
            node = prev[node];
        }
        for (int i = pathLen - 1; i >= 0; i--) {
            printf("%c ", path[i]);
        }
        printf("\nDistance: %d\n", dist[destIndex]);
    }
}

void addDefaultGraph(Graph* graph) {
    addNode(graph, 0, 'A');
    addNode(graph, 1, 'B');
    addNode(graph, 2, 'C');
    addNode(graph, 3, 'D');
    addNode(graph, 4, 'E');
    addNode(graph, 5, 'F');

    addEdges(graph, 'A', 2, (char[]){'B', 'C'}, (int[]){6, 3});
    addEdges(graph, 'B', 3, (char[]){'A', 'C', 'D'}, (int[]){6, 2, 5});
    addEdges(graph, 'C', 4, (char[]){'A', 'B', 'D', 'E'}, (int[]){3, 2, 3, 4});
    addEdges(graph, 'D', 4, (char[]){'B', 'C', 'E', 'F'}, (int[]){5, 3, 2, 3});
    addEdges(graph, 'E', 3, (char[]){'C', 'D', 'F'}, (int[]){4, 2, 5});
    addEdges(graph, 'F', 2, (char[]){'D', 'E'}, (int[]){3, 5});

    printf("Default graph initialized.\n");
}

int main() {
    Graph* graph = createGraph();
    addDefaultGraph(graph);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add node\n");
        printf("2. Add edges\n");
        printf("3. Calculate shortest path (Dijkstra)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char id;
                printf("Enter node ID: ");
                scanf(" %c", &id);
                if (getNodeIndex(graph, id) != -1) {
                    printf("Node %c already exists.\n", id);
                    break;
                }
                addNode(graph, graph->numNodes, id);
                printf("Node %c added.\n", id);
                break;
            }
            case 2: {
                char src;
                int numEdges;
                printf("Enter source node and number of edges: ");
                scanf(" %c %d", &src, &numEdges);
                char dests[numEdges];
                int weights[numEdges];
                for (int i = 0; i < numEdges; i++) {
                    printf("Enter destination and weight for edge %d: ", i + 1);
                    scanf(" %c %d", &dests[i], &weights[i]);
                }
                addEdges(graph, src, numEdges, dests, weights);
                printf("Edges added for %c.\n", src);
                break;
            }
            case 3: {
                char start, end;
                printf("Enter start and end nodes: ");
                scanf(" %c %c", &start, &end);
                dijkstra(graph, start, end);
                break;
            }
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    for (int i = 0; i < graph->numNodes; i++) {
        Edge* edge = graph->adjList[i];
        while (edge) {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(graph);

    return 0;
}
