#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to find the minimum key value vertex
int minKey(const vector<int>& key, const vector<bool>& inMST) {
    int min = numeric_limits<int>::max();
    int min_index = -1;

    for (size_t v = 0; v < key.size(); ++v) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the minimum spanning tree
void printMST(const vector<int>& parent, const vector<int>& graph, int V) {
    cout << "Edges of the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " : " << graph[parent[i] * V + i] << endl;
    }
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(const vector<int>& graph, int V) {
    // Create a vector to store the parent of each vertex in the MST
    vector<int> parent(V, -1);

    // Create a vector to store the key value of each vertex
    vector<int> key(V, numeric_limits<int>::max());

    // Create a vector to store whether each vertex is included in the MST
    vector<bool> inMST(V, false);

    // Add the first vertex to the MST with key value 0
    key[0] = 0;

    // Find the minimum spanning tree
    for (int count = 0; count < V - 1; ++count) {
        // Find the vertex with the minimum key value
        int u = minKey(key, inMST);

        // Include the vertex in the MST
        inMST[u] = true;

        // Update the key value and parent for each adjacent vertex
        for (int v = 0; v < V; ++v) {
            if (graph[u * V + v] != 0 && !inMST[v] && graph[u * V + v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u * V + v];
            }
        }
    }

    // Print the minimum spanning tree
    printMST(parent, graph, V);
}

int main() {
    // Example graph represented as a 1D array (adjacency matrix)
    int graph[] = {
        0, 2, 0, 6, 0,
        2, 0, 3, 8, 5,
        0, 3, 0, 0, 7,
        6, 8, 0, 0, 9,
        0, 5, 7, 9, 0
    };

    // Number of vertices in the graph
    int V = 5;

    // Find and print the minimum spanning tree
    primMST(vector<int>(graph, graph + V * V), V);

    return 0;
}

