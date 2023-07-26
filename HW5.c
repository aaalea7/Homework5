#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 9

// Node to store an adjacent vertex
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// BFS structure
typedef struct Queue {
    int front, rear;
    int arr[MAX_VERTICES];
} Q;

// create a new node for the adjacency list
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;
}

// initialize the queue
void initQueue(Q* q) {
    q->front = q->rear = -1;
}

// check if the queue is empty
int isEmpty(Q* q) {
    return q->front == -1;
}

// enqueue a vertex into the queue
void enqueue(Q* q, int vertex) {
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = vertex;
}

// dequeue a vertex from the queue
int dequeue(Q* q) {
    int vertex = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return vertex;
}

// perform BFS starting from vertex 0
void bfs(Node* graph[]) {
    Q q;
    initQueue(&q);
    int visited[MAX_VERTICES] = {0};

    visited[0] = 1;
    enqueue(&q, 0);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        Node* temp = graph[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    Node* graph[MAX_VERTICES] = {NULL};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 6);
    addEdge(graph, 2, 5);
    addEdge(graph, 5, 8);
    addEdge(graph, 4, 7);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);

    printf("BFS: ");
    bfs(graph);
    printf("\n");

    return 0;
}
