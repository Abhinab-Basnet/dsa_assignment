// How can we implement the undirected graph using the adjacency matrix? Write a function
// that implements the BFS and DFS technique to traverse through the graph. Demonstrate
// the use of your program with an example graph.


#include<stdio.h>

#define MAX 10

int adjMatrix[MAX][MAX];
int visited[MAX];
int n;

void createGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int i;

    
    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int start, i;

    createGraph();

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);


    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
