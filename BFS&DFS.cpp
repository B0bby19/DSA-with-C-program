#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    struct Node* adjList[MAX_NODES];
    int visited[MAX_NODES];
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize graph
void initGraph(struct Graph* graph, int nodes) {
    for (int i = 0; i < nodes; ++i) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Since it's an undirected graph, add edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Depth-First Search (DFS) function
void DFS(struct Graph* graph, int start) {
    struct Node* adjList = graph->adjList[start];
    struct Node* temp = adjList;

    graph->visited[start] = 1;
    printf("Visited node: %d\n", start);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Breadth-First Search (BFS) function
void BFS(struct Graph* graph, int start, int nodes) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    int dequeued;

    queue[rear++] = start;
    graph->visited[start] = 1;

    while (front < rear) {
        dequeued = queue[front++];

        printf("Visited node: %d\n", dequeued);

        struct Node* temp = graph->adjList[dequeued];
        while (temp != NULL) {
            int connectedVertex = temp->vertex;
            if (graph->visited[connectedVertex] == 0) {
                queue[rear++] = connectedVertex;
                graph->visited[connectedVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Edge\n");
    printf("2. Perform BFS\n");
    printf("3. Perform DFS\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Graph graph;
    int choice, nodes, edges, src, dest;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodes);

    initGraph(&graph, nodes);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; ++i) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter edge (source destination): ");
                scanf("%d %d", &src, &dest);
                addEdge(&graph, src, dest);
                break;
            case 2:
                printf("\nBFS Traversal:\n");
                for (int i = 0; i < nodes; ++i) {
                    if (graph.visited[i] == 0) {
                        BFS(&graph, i, nodes);
                    }
                }
                break;
            case 3:
                printf("\nDFS Traversal:\n");
                for (int i = 0; i < nodes; ++i) {
                    if (graph.visited[i] == 0) {
                        DFS(&graph, i);
                    }
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

