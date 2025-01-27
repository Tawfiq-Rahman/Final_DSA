 BFS From Edges List

 #include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS
void BFS(int startNode, const vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false); // To keep track of visited nodes
    queue<int> q;                                // Queue for BFS traversal

    visited[startNode] = true;  // Mark the start node as visited
    q.push(startNode);          // Enqueue the start node

    cout << "BFS: ";
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();               // Dequeue the current node
        cout << currentNode;   // Process the node

        // Traverse all adjacent nodes
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark the neighbor as visited
                q.push(neighbor);         // Enqueue the neighbor
            }
        }

        if (!q.empty()) cout << " -> "; // Add separator for BFS traversal
    }
    cout << endl;
}

int main() {
    int nodes, edges;
    cout << "No of nodes: ";
    cin >> nodes;
    cout << "No of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(nodes); // Adjacency list for the graph

    cout << "Enter all edges:" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (since the graph is undirected)
    }

    int startNode;
    cout << "Enter starting node: ";
    cin >> startNode;

    // Perform BFS
    BFS(startNode, adjList);

    return 0;
}

/*
Sample Input:
No of nodes: 7
No of edges: 9
Enter all edges:
0 1
0 3
1 2
1 3
1 5
1 6
2 3
2 4
2 5
Enter starting node: 0

Sample Output:
BFS: 0 -> 1 -> 3 -> 2 -> 5 -> 6 -> 4
*/


BFS From Adjacency Matrix

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS
void BFS(int startNode, const vector<vector<int>>& adjMatrix) {
    vector<bool> visited(adjMatrix.size(), false); // To keep track of visited nodes
    queue<int> q;                                  // Queue for BFS traversal

    visited[startNode] = true;  // Mark the start node as visited
    q.push(startNode);          // Enqueue the start node

    cout << "BFS: ";
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();               // Dequeue the current node
        cout << currentNode;   // Process the node

        // Traverse all adjacent nodes
        for (int i = 0; i < adjMatrix[currentNode].size(); ++i) {
            if (adjMatrix[currentNode][i] == 1 && !visited[i]) { // Check adjacency
                visited[i] = true; // Mark the neighbor as visited
                q.push(i);         // Enqueue the neighbor
            }
        }

        if (!q.empty()) cout << " -> "; // Add separator for BFS traversal
    }
    cout << endl;
}

int main() {
    int nodes;
    cout << "No of nodes: ";
    cin >> nodes;

    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0)); // Adjacency matrix

    cout << "Enter adjacency matrix:" << endl;
    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j < nodes; ++j) {
            cin >> adjMatrix[i][j]; // Fill the adjacency matrix
        }
    }

    int startNode;
    cout << "Enter starting node: ";
    cin >> startNode;

    // Perform BFS
    BFS(startNode, adjMatrix);

    return 0;
}

/*
Sample Input:
No of nodes: 7
Enter adjacency matrix:
0 1 0 1 0 0 0
1 0 1 1 0 1 1
0 1 0 1 1 1 0
1 1 1 0 1 0 0
0 0 1 1 0 0 1
0 1 1 0 0 0 0
0 1 0 0 1 0 0
Enter starting node: 0

Sample Output:
BFS: 0 -> 1 -> 3 -> 2 -> 5 -> 6 -> 4
*/



Shortest Path Using BFS

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Function to find the shortest path using BFS
void ShortestPath(int startNode, int targetNode, const vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false); // To keep track of visited nodes
    vector<int> parent(adjList.size(), -1);     // To store the parent of each node for path reconstruction
    queue<int> q;                               // Queue for BFS traversal

    visited[startNode] = true; // Mark the start node as visited
    q.push(startNode);         // Enqueue the start node

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop(); // Dequeue the current node

        // Traverse all adjacent nodes
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;  // Mark the neighbor as visited
                parent[neighbor] = currentNode; // Store the parent of the neighbor
                q.push(neighbor);          // Enqueue the neighbor

                if (neighbor == targetNode) { // Stop BFS if the target node is found
                    break;
                }
            }
        }
    }

    // Reconstruct the shortest path from startNode to targetNode
    if (!visited[targetNode]) {
        cout << "No path exists." << endl;
        return;
    }

    stack<int> path; // Stack to store the path in reverse order
    for (int node = targetNode; node != -1; node = parent[node]) {
        path.push(node);
    }

    cout << "Shortest Path: ";
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int nodes, edges;
    cout << "No of nodes: ";
    cin >> nodes;
    cout << "No of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(nodes); // Adjacency list for the graph

    cout << "Enter all edges:" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (since the graph is undirected)
    }

    int startNode, targetNode;
    cout << "Enter starting node: ";
    cin >> startNode;
    cout << "Enter targeted node: ";
    cin >> targetNode;

    // Find the shortest path
    ShortestPath(startNode, targetNode, adjList);

    return 0;
}

/*
Sample Input:
No of nodes: 7
No of edges: 9
Enter all edges:
0 1
0 3
1 2
1 3
1 5
1 6
2 3
2 4
2 5
Enter starting node: 0
Enter targeted node: 5

Sample Output:
Shortest Path: 0 -> 1 -> 5
*/


 Check Bipartite Graph Using BFS

 #include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to check if the graph is bipartite using BFS
bool IsBipartite(const vector<vector<int>>& adjList) {
    vector<int> color(adjList.size(), -1); // Initialize all nodes with no color (-1)

    for (int startNode = 0; startNode < adjList.size(); ++startNode) {
        if (color[startNode] == -1) { // If the node has not been visited
            queue<int> q;
            color[startNode] = 0; // Assign the first color (0)
            q.push(startNode);

            while (!q.empty()) {
                int currentNode = q.front();
                q.pop();

                for (int neighbor : adjList[currentNode]) {
                    if (color[neighbor] == -1) {
                        // Assign the opposite color to the neighbor
                        color[neighbor] = 1 - color[currentNode];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[currentNode]) {
                        // If the neighbor has the same color, it's not bipartite
                        return false;
                    }
                }
            }
        }
    }
    return true; // If no conflicts are found, the graph is bipartite
}

int main() {
    int nodes, edges;
    cout << "No of nodes: ";
    cin >> nodes;
    cout << "No of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(nodes); // Adjacency list for the graph

    cout << "Enter all edges:" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (since the graph is undirected)
    }

    // Check if the graph is bipartite
    if (IsBipartite(adjList)) {
        cout << "Is Bipartite: Yes" << endl;
    } else {
        cout << "Is Bipartite: No" << endl;
    }

    return 0;
}

/*
Sample Input:
No of nodes: 7
No of edges: 9
Enter all edges:
0 1
0 3
1 2
1 3
1 5
1 6
2 3
2 4
2 5
Enter all edges:
3 4
4 6

Sample Output:
Is Bipartite: No
*/


Find Farthest Node From Starting Node


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the farthest node using BFS
int FarthestNode(int startNode, const vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false); // To keep track of visited nodes
    queue<pair<int, int>> q; // Queue to store node and its distance
    visited[startNode] = true;
    q.push({startNode, 0});

    int farthestNode = startNode;
    int maxDistance = 0;

    while (!q.empty()) {
        int currentNode = q.front().first;
        int currentDistance = q.front().second;
        q.pop();

        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, currentDistance + 1});

                if (currentDistance + 1 > maxDistance) {
                    maxDistance = currentDistance + 1;
                    farthestNode = neighbor;
                }
            }
        }
    }

    return farthestNode;
}

int main() {
    int nodes, edges;
    cout << "No of nodes: ";
    cin >> nodes;
    cout << "No of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(nodes); // Adjacency list for the graph

    cout << "Enter all edges:" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (since the graph is undirected)
    }

    int startNode;
    cout << "Enter starting node: ";
    cin >> startNode;

    // Find the farthest node
    int farthest = FarthestNode(startNode, adjList);
    cout << "Farthest Node: " << farthest << endl;

    return 0;
}

/*
Sample Input:
No of nodes: 7
No of edges: 9
Enter all edges:
0 1
0 3
1 2
1 3
1 5
1 6
2 3
2 4
2 5
Enter starting node: 1

Sample Output:
Farthest Node: 4
*/





DFS From Edges List



#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS
void DFS(int currentNode, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[currentNode] = true; // Mark the current node as visited
    cout << currentNode << " "; // Process the node

    // Traverse all adjacent nodes
    for (size_t i = 0; i < adjList[currentNode].size(); ++i) {
        int neighbor = adjList[currentNode][i];
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited); // Recursively visit the neighbor
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(nodes);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (if the graph is undirected)
    }

    int startNode;
    cout << "Enter the start node for DFS: ";
    cin >> startNode;

    // To keep track of visited nodes
    vector<bool> visited(nodes, false);

    // Perform DFS
    cout << "DFS Traversal: ";
    DFS(startNode, adjList, visited);
    cout << endl;

    return 0;
}

/*
Sample Input:
Enter the number of nodes and edges: 7 9
Enter the edges (u v):
0 1
0 3
1 2
1 3
1 5
1 6
2 3
2 4
2 5
Enter the start node for DFS: 0

Sample Output:
DFS Traversal: 0 1 2 3 4 5 6
*/


 DFS From Adjacency Matrix


 #include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS
void DFS(int currentNode, const vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[currentNode] = true; // Mark the current node as visited
    cout << currentNode << " "; // Process the node

    // Traverse all adjacent nodes
    for (int i = 0; i < adjMatrix[currentNode].size(); ++i) {
        if (adjMatrix[currentNode][i] == 1 && !visited[i]) { // Check adjacency and visitation
            DFS(i, adjMatrix, visited); // Recursively visit the neighbor
        }
    }
}

int main() {
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    // Adjacency matrix representation of the graph
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));

    cout << "Enter adjacency matrix:" << endl;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    int startNode;
    cout << "Enter the start node for DFS: ";
    cin >> startNode;

    // To keep track of visited nodes
    vector<bool> visited(nodes, false);

    // Perform DFS
    cout << "DFS Traversal: ";
    DFS(startNode, adjMatrix, visited);
    cout << endl;

    return 0;
}

/*
Sample Input:
Enter the number of nodes: 7
Enter adjacency matrix:
0 1 0 1 0 0 0
1 0 1 1 0 1 1
0 1 0 1 1 1 0
1 1 1 0 1 0 0
0 0 1 1 0 0 1
0 1 1 0 0 0 0
0 1 0 0 1 0 0
Enter the start node for DFS: 0

Sample Output:
DFS Traversal: 0 1 2 3 4 5 6
*/


Shortest Path Using DFS


#include <iostream>
#include <vector>
using namespace std;

// Function to find the shortest path using DFS
bool DFSPath(int currentNode, int targetNode, const vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& path) {
    visited[currentNode] = true; // Mark the current node as visited
    path.push_back(currentNode); // Add the current node to the path

    if (currentNode == targetNode) { // If we reach the target node
        return true;
    }

    for (int neighbor : adjList[currentNode]) {
        if (!visited[neighbor]) {
            if (DFSPath(neighbor, targetNode, adjList, visited, path)) {
                return true; // If the path to the target is found, stop recursion
            }
        }
    }

    path.pop_back(); // Backtrack if the path is not found
    return false;
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<vector<int>> adjList(nodes); // Adjacency list representation

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (if the graph is undirected)
    }

    int startNode, targetNode;
    cout << "Enter starting node: ";
    cin >> startNode;
    cout << "Enter target node: ";
    cin >> targetNode;

    vector<bool> visited(nodes, false); // To keep track of visited nodes
    vector<int> path;                   // To store the path

    if (DFSPath(startNode, targetNode, adjList, visited, path)) {
        cout << "Shortest Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "No path found!" << endl;
    }

    return 0;
}

/*
Sample Input:
Enter the number of nodes and edges: 7 9
Enter the edges (u v):
0 1
0 3
1 2
1 3
1 5
1 6
2 3
2 4
2 5
Enter starting node: 0
Enter target node: 5

Sample Output:
Shortest Path: 0 -> 1 -> 5
*/


Check Bipartite Graph Using DFS



#include <iostream>
#include <vector>
using namespace std;

// Function to check if the graph is bipartite using DFS
bool DFSBipartite(int currentNode, const vector<vector<int>>& adjList, vector<int>& colors, int currentColor) {
    colors[currentNode] = currentColor; // Assign the current node a color

    for (int neighbor : adjList[currentNode]) {
        if (colors[neighbor] == -1) { // If the neighbor is unvisited
            // Recursively assign the opposite color to the neighbor
            if (!DFSBipartite(neighbor, adjList, colors, 1 - currentColor)) {
                return false;
            }
        } else if (colors[neighbor] == currentColor) {
            // If the neighbor has the same color, it's not bipartite
            return false;
        }
    }

    return true; // If no conflicts are found, return true
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<vector<int>> adjList(nodes); // Adjacency list representation

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (if the graph is undirected)
    }

    vector<int> colors(nodes, -1); // Initialize all nodes with no color (-1)

    bool isBipartite = true; // Assume the graph is bipartite initially
    for (int i = 0; i < nodes; ++i) {
        if (colors[i] == -1) { // If the node has not been visited
            if (!DFSBipartite(i, adjList, colors, 0)) {
                isBipartite = false;
                break;
            }
        }
    }

    if (isBipartite) {
        cout << "Is Bipartite: Yes" << endl;
    } else {
        cout << "Is Bipartite: No" << endl;
    }

    return 0;
}

/*
Sample Input:
Enter the number of nodes and edges: 7 9
Enter the edges (u v):
0 1
0 3
1 2
1 3
1 5
1 6
2 3
2 4
2 5
3 4
4 6

Sample Output:
Is Bipartite: No
*/



Find Farthest Node From Starting Node Using DFS


#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and find the farthest node
void DFSFarthest(int currentNode, const vector<vector<int>>& adjList, vector<bool>& visited, int currentDistance, int& maxDistance, int& farthestNode) {
    visited[currentNode] = true; // Mark the current node as visited

    // Update the farthest node and maximum distance if needed
    if (currentDistance > maxDistance) {
        maxDistance = currentDistance;
        farthestNode = currentNode;
    }

    // Traverse all adjacent nodes
    for (int neighbor : adjList[currentNode]) {
        if (!visited[neighbor]) {
            DFSFarthest(neighbor, adjList, visited, currentDistance + 1, maxDistance, farthestNode);
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<vector<int>> adjList(nodes); // Adjacency list representation

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (if the graph is undirected)
    }

    int startNode;
    cout << "Enter the start node: ";
    cin >> startNode;

    vector<bool> visited(nodes, false); // To keep track of visited nodes
    int maxDistance = 0;                // To store the maximum distance
    int farthestNode = startNode;       // To store the farthest node

    // Perform DFS to find the farthest node
    DFSFarthest(startNode, adjList, visited, 0, maxDistance, farthestNode);

    cout << "Farthest Node: " << farthestNode << endl;

    return 0;
}

/*
Sample Input:
Enter the number of nodes and edges: 7 9
Enter the edges (u v):
0 1
0 3
1 2
1 3
1 5
1 6
2 3
2 4
2 5
Enter the start node: 1

Sample Output:
Farthest Node: 4
*/



