#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Graph class
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    // Constructor
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Function to perform Breadth First Search
    void BFS(int start) {
        // Queue for BFS
        queue<int> q;

        // Set to keep track of visited vertices
        unordered_set<int> visited;

        // Enqueue the starting vertex
        q.push(start);
        visited.insert(start);

        cout << "Breadth First Traversal: ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Process the current vertex
            cout << u << " ";

            // Enqueue adjacent vertices of the current vertex
            for (int v : adj[u]) {
                if (visited.find(v) == visited.end()) {
                    q.push(v);
                    visited.insert(v);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    // Create a graph
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    // Perform BFS starting from vertex 0
    g.BFS(0);

    return 0;
}

