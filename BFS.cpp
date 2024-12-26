#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// This function performs a BFS search on a graph represented as an adjacency list.
// The graph is assumed to be undirected.
//
// Parameters:
// - adjacency_list: a vector of vectors representing the adjacency list of the graph
// - start_vertex: the index of the starting vertex
//
// Returns:
// - a vector of integers representing the BFS traversal order of the graph,
//   starting from the start_vertex


vector<int> bfs(const vector<vector<int>>& adjacency_list, int start_vertex) {
    int num_vertices = adjacency_list.size(); // Number of vertices in the graph
    vector<bool> track_visited(num_vertices, false); // Boolean array to track visited vertices
    vector<int> bfs_order; // Vector to store the BFS traversal order

    queue<int> vertex_queue; // Queue to hold the vertices to be visited
    vertex_queue.push(start_vertex); // Add the starting vertex to the queue
    track_visited[start_vertex] = true; // Mark the starting vertex as visited

    while (!vertex_queue.empty()) {
        // Print the state of the queue
        cout << "Queue: ";
        queue<int> temp_queue = vertex_queue; // Copy queue to print its elements
        while (!temp_queue.empty()) {
            cout << temp_queue.front() << " ";
            temp_queue.pop();
        }
        cout << endl;

        int current_vertex = vertex_queue.front(); // Get the next vertex in the queue
        vertex_queue.pop(); // Remove the vertex from the queue

        // Print the node being visited
        cout << "Processing vertex: " << current_vertex << endl;

        // Add the vertex to the traversal order
        bfs_order.push_back(current_vertex);

        // Add all the unvisited neighbors of current_vertex to the queue
        for (int neighbor_vertex : adjacency_list[current_vertex]) {
            if (!track_visited[neighbor_vertex]) {
                // Print the neighbor being added to the queue
                cout << "Adding neighbor to queue: " << neighbor_vertex << endl;

                vertex_queue.push(neighbor_vertex);
                track_visited[neighbor_vertex] = true;
            }
        }

        // Print the vertices visited so far
        cout << "BFS Ordered vertices so far: ";
        for (int vertex : bfs_order) {
            cout << vertex << " ";
        }
        cout << endl << endl;
    }

    return bfs_order;
}

int main() {
    // Create an adjacency list for a graph with 5 vertices
    vector<vector<int>> adjacency_list = {
        {1, 2, 3},  // Vertex 0 has neighbors 1 and 2
        {0, 3, 1},  // Vertex 1 has neighbors 0, 3, and 4
        {3, 2},  // Vertex 2 has neighbors 0 and 4
        {1, 3},  // Vertex 3 has neighbors 1 and 4
    };

    vector<int> bfs_order = bfs(adjacency_list, 3);

    cout << "BFS traversal order: ";
    for (int vertex : bfs_order) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
