## Dijkstra's Shortest Path Algorithm Implementation

## INTRODUCTION
Dijkstra's algorithm is a graph algorithm used to fing the shortest path from a single source vertex to all other vertices in a weighted graph with non negative edge weights.

- The algorithm maintains a set of visited vertices whose shortest distance from the source is already known.

-  At each step, it selects the unvisited vertex with the minimum distance from the source and updates the distances of its neighbors.

This program demonstrates Dijkstra’s algorithm on a graph represented as an adjacency matrix.

## OBJECTIVES

- To understand the concept of Dijkstra’s shortest path algorithm.

- To implement the minDistance function to select the next vertex.

- To compute the shortest path from a source vertex to all other vertices.

- To use an adjacency matrix to represent a weighted graph.

- To display the shortest distances from the source vertex.

## DATA STRUCTURES USED
This program uses:
```bash
int graph[V][V];
int dist[V];
bool visited[V];
```
**EXPLANATION**

- **graph[V][V]**: Represents the weighted adjacency matrix of the graph. graph[i][j] stores the weight of the edge from vertex i to vertex j.

- **dist[V]**: Stores the shortest distance of each vertex from the source vertex.

- **visited[V]**: Tracks which vertices have been processed. true indicates the vertex has been visited, false otherwise.

## DESCRIPTION OF FUNCTION IMPLEMENTED

1. minDistance(int dist[], bool visted[])

**Purpose**

-    Select the vertex with the minimum distance from the source among the unvisited vertices.
```bash
int minDistance(int dist[], bool visited[]){
    int min = INT_MAX, min_index;
    for(int v = 0; v < V; v++){
        if(!visited[v] && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
```
**Description**

- Initializes min to maximum integer value.

- Iterates through all vertices.

- Updates min and min_index if an unvisited vertex with a smaller distance is found.

- Returns the index of the vertex with the minumum distance.

2. printSolution(int dist[])

**Purpose**

Displays the shortest distance from the source vertex to all other vertices.

```bash
void printSolution(int dist[]){
    printf("Vertex \t Distance from Source\n");
    for(int i = 0; i < V; i++){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
```
**Description**

- Traverses the dist array.

- Prints each vertex and its corresponding distance from the source.

3. dijkstra(int graph[V][V], int src)

**Purpose**

Implements Dijkstra's algorithm to compute the shortest paths from the source vertex src.
```bash
void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;

    for(int count = 0; count < V - 1; count++){
        int u = minDistance(dist, visited);
        visited[u] = true;

        for(int v = 0; v < V; v++){
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
}
```
**Description**

- Initializes all distances to infinity (INT_MAX) and visited flags to false.

- Sets the distance of the source vertex to 0.

- Repeat the process V-1 times:
Selects the unvisited vertex u with the minimum distance. Marks u as visited. Updates the distances of all adjacent unvisited vertices if a shorter path is found through u.

- Calls printSolution to display the final shortest distances.

## ORGANIZATION OF main() FUNCTION

```bash
int main(){
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };
    int src = 0;
    dijkstra(graph, src);
    return 0;
}
```
**STEPS PERFORMED IN MAIN() FUNCTION**

- Defines a 5-vertex weighted graph using an adjacency matrix.

- Sets the source vertex as 0.

- Calls dijsktra() to compute the shortest paths.

- Displays the shortest distances using printSolution().

## SAMPLE INPUT/OUPUT

**Input**
```bash
graph[V][V] = {
    {0, 10, 0, 30, 100},
    {10, 0, 50, 0, 0},
    {0, 50, 0, 20, 10},
    {30, 0, 20, 0, 60},
    {100, 0, 10, 60, 0}
}
```
**Output**
```bash
Vertex   Distance from Source
0        0
1        10
2        50
3        30
4        60
```
## CONCLUSION
This program demonstrates Dijkstra’s algorithm to find the shortest path from a single source to all vertices in a weighted graph. It highlights:

- Selection of the next vertex with the minimum distance using minDistance().

- Efficient updating of distances using adjacency matrix representation.

- Recursive updating of shortest paths until all vertices are processed.

The program effectively illustrates how Dijkstra’s algorithm computes shortest paths in graphs with non-negative edge weights.