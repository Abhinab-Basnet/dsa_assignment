## BFS and DFS Traversal in Graph 

## INTRODUCTION
Graphs are non-linear data structure consisting of vertices and edges connecting them.Graph traversal refers to visiting all the vertices in a systematic way. This program demonstrates Breadth-First Search (BFS) and Depth-First Search (DFS) traversal of a graph using an adjacency matrix representation. BFS visits vertices level by level, while DFS explores as far as possible along each branch before backtracking.

## OBJECTIVES
1. To create a graph using an adjacency matrix.

2. To implement Breadth-First Search (BFS) traversal.

3. To implement Depth-First Search (DFS) traversal.

4. To mark visited vertices to avoid revisiting.

5. To understand the working of queue in BFS and 
recursion in DFS.


## DATA STRUCTURE USED
```bash
#define MAX 10

int adjMatrix[MAX][MAX];
int visited[MAX];        
int n;                  
```
**EXPLANATION**

- adjMatrix[MAX][MAX]

Stores the edges between vertices. A value of 1 indicates an edge; 0 indicates no edge.

- visited[MAX]

Keeps track of whether a vertex has been visited to avoid cycles.

- n

The total number of vertices in the graph.

- queue[MAX]

Implements the BFS traversal order using a linear queue.

## DESCRIPTION OF FUNCTION IMPLEMENTED

1. createGraph()

**Purpose**

To create a graph by reading the number of vertices and the adjacency matrix.
```bash
void createGraph(){
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i=0 ; i<n; i++){
        for (j=0; j<n; j++){
            scanf("%d", &adjMatrix[i][j]);
        }
    }
}
```
**Description**

- Prompts the user to input the number of vertices n.

- Reads the adjacency matrix values from the user.

- Stores the connections between vertices in adjMatrix.

2. BFS(int start)

**Purpose:**

To traverse the graph in Breadth-First Search order starting from the given vertex.
```bash
void BFS(int start){
    int queue[MAX], front=0, rear = 0;
    int i;

    for(i=0; i<n; i++)
        visited[i]=0;

    visited[start]=1;
    queue[rear++]=start;

    printf("BFS Traversal: ");
    while(front < rear){
        int v = queue[front++];
        printf("%d ", v);

        for(i=0 ; i< n; i++){
            if(adjMatrix[v][i]==1 && !visited[i]){
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
    printf("\n");
}
```
**Description**

-  Initializes all vertices as unvisited.

-  Marks the starting vertex as visited and enqueues it.

-  Repeatedly dequeues a vertex, prints it, and enqueues all its unvisited neighbors.

-  Continues until all reachable vertices are visited.




3. DFS(int v)

   **Purpose:**

To traverse the graph in Depth-First Search order using recursion.
```bash
void DFS(int v){
    int i;
    printf("%d ", v);
    visited[v]=1;

    for(i=0; i<n; i++){
        if(adjMatrix[v][i]==1 && !visited[i]){
            DFS(i);
        }
    }
}
```
**Description**

-  Marks the current vertex as visited and prints it.

-  Recursively visits all unvisited neighbors of the current vertex.

-  DFS explores as far as possible along each branch before backtracking.

## ORGANIZATION OF main() FUNCTION

```bash
int main(){
    int start;

    createGraph();
    
    printf("Enter starting vertex: ");
    scanf("%d",&start);

    BFS(start);

    for(int i=0; i<n; i++){
        visited[i]=0;
    }

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
```
**STEPS PERFORMED IN MAIN():**

1. Calls createGraph() to input the graph.

2. Reads the starting vertex for traversal.

3. Performs BFS traversal from the starting vertex.

4. Resets the visited array before DFS.

5. Performs DFS traversal from the starting vertex.

6. Prints BFS and DFS traversal results.

## SAMPLE INPUT/OUTPUT
**Input**
```bash
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter starting vertex: 0
```
**Output**
```bash
BFS Traversal: 0 1 2 3
DFS Traversal: 0 1 3 2
```

## CONCLUSION
This program demonstrates the implementation of BFS and DFS graph traversals using an adjacency matrix. BFS uses a queue to traverse level by level, while DFS uses recursion to explore depth-first. The program highlights the importance of marking visited vertices to prevent infinite loops and ensures correct traversal order.