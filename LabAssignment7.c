/*
Design a program to represent a social network using a graph. Each user is a node, and 
connections are edges. The system should support the following operations:
a. Add connections between users.
b. Perform Breadth First Search (BFS) to explore all connected users.
c. Perform Depth First Search (DFS) to traverse the network.
*/
#include <stdio.h>
#define MAX 10
// Adjacency matrix and number of users
int adj[MAX][MAX];
int n;
// Add a connection between two users
void addConnection(int u, int v)
{
 // Check whether user IDs are valid
 if (u < 0 || u >= n || v < 0 || v >= n)
 {
 printf("Invalid user ID!\n");
 return;
 }
 // Do not allow a user to connect to themselves
 if (u == v)
 {
 printf("Self-connection is not allowed!\n");
 return;
 }
 // Graph is undirected, so set both directions
 adj[u][v] = 1;
 adj[v][u] = 1;
 printf("Connection added successfully!\n");
}
// Display the adjacency matrix
void displayMatrix()
{
 int i, j; printf("\nAdjacency Matrix:\n");
 for (i = 0; i < n; i++)
 {
 for (j = 0; j < n; j++)
 {
 printf("%d ", adj[i][j]);
 }
 printf("\n");
 }
}
// Breadth First Search using an array as a queue
void BFS(int start)
{
 int visited[MAX] = {0};
 int queue[MAX];
 int front = 0, rear = 0;
 int current, i;
 // Validate starting user
 if (start < 0 || start >= n)
 {
 printf("Invalid starting user ID!\n");
 return;
 }
 // Mark start as visited and add it to queue
 visited[start] = 1;
 queue[rear++] = start;
 printf("BFS Traversal: ");
 while (front < rear)
 {
 // Remove the first user from the queue
 current = queue[front++];
 printf("%d ", current);
 // Check all possible neighbours
 for (i = 0; i < n; i++)
 {
 if (adj[current][i] == 1 && !visited[i])
 { visited[i] = 1;
 queue[rear++] = i;
 }
 }
 }
 printf("\n");
}
// Helper function for recursive DFS
void DFSHelper(int current, int visited[])
{
 int i;
 // Mark and display the current user
 visited[current] = 1;
 printf("%d ", current);
 // Visit every unvisited neighbour
 for (i = 0; i < n; i++)
 {
 if (adj[current][i] == 1 && !visited[i])
 {
 DFSHelper(i, visited);
 }
 }
}
// Depth First Search
void DFS(int start)
{
 int visited[MAX] = {0};
 // Validate starting user
 if (start < 0 || start >= n)
 {
 printf("Invalid starting user ID!\n");
 return;
 }
 printf("DFS Traversal: ");
 DFSHelper(start, visited);
 printf("\n");
} int main()
{
 int choice, u, v, start;
 int i, j;
 printf("Enter number of users (1-10): ");
 scanf("%d", &n);
 // Validate the number of users
 if (n < 1 || n > MAX)
 {
 printf("Invalid number of users!\n");
 return 0;
 }
 // Initialize the adjacency matrix with zeros
 for (i = 0; i < n; i++)
 {
 for (j = 0; j < n; j++)
 {
 adj[i][j] = 0;
 }
 }
 do
 {
 printf("\n--- Social Network Menu ---\n");
 printf("1. Add Connection\n");
 printf("2. Display Adjacency Matrix\n");
 printf("3. BFS Traversal\n");
 printf("4. DFS Traversal\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 printf("Enter two user IDs (0 to %d): ", n - 1);
 scanf("%d %d", &u, &v);
 addConnection(u, v);
 break; case 2:
 displayMatrix();
 break;
 case 3:
 printf("Enter starting user ID: ");
 scanf("%d", &start);
 BFS(start);
 break;
 case 4:
 printf("Enter starting user ID: ");
 scanf("%d", &start);
 DFS(start);
 break;
 case 5:
 printf("Exiting program...\n");
 break;
 default:
 printf("Invalid choice!\n");
 }
 } while (choice != 5);
 return 0;
}
/*
output:
Enter number of users (1-10): 7
--- Social Network Menu ---
1. Add Connection
2. Display Adjacency Matrix
3. BFS Traversal
4. DFS Traversal
5. Exit
Enter your choice: 1
Enter two user IDs (0 to 6): 3
6 Connection added successfully!
--- Social Network Menu ---
1. Add Connection
2. Display Adjacency Matrix
3. BFS Traversal
4. DFS Traversal
5. Exit
Enter your choice: 2
Adjacency Matrix:
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 0 0 0 1 
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 0 1 0 0 0 
--- Social Network Menu ---
1. Add Connection
2. Display Adjacency Matrix
3. BFS Traversal
4. DFS Traversal
5. Exit
Enter your choice: 3
Enter starting user ID: 4
BFS Traversal: 4 
--- Social Network Menu ---
1. Add Connection
2. Display Adjacency Matrix
3. BFS Traversal
4. DFS Traversal
5. Exit
Enter your choice: 4
Enter starting user ID: 3
DFS Traversal: 3 6 
--- Social Network Menu ---
1. Add Connection
2. Display Adjacency Matrix
3. BFS Traversal
4. DFS Traversal 5. Exit
Enter your choice: 5
Exiting program...
*/
