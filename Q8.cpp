#include <iostream>
#include <vector>
#include <stack>
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

    // Function to perform Depth First Search
    void DFS(int start) {
        // Stack for DFS
        stack<int> st;

        // Set to keep track of visited vertices
        unordered_set<int> visited;

        // Push the starting vertex onto the stack
        st.push(start);

        cout << "Depth First Traversal: ";

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            // Process the current vertex if not visited
            if (visited.find(u) == visited.end()) {
                cout << u << " ";
                visited.insert(u);

                // Push adjacent vertices onto the stack
                for (int v : adj[u]) {
                    if (visited.find(v) == visited.end()) {
                        st.push(v);
                    }
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

    // Perform DFS starting from vertex 0
    g.DFS(0);

    return 0;
}

