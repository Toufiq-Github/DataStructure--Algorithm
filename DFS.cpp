
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Define colors using characters
const char WHITE = 'W';
const char GRAY = 'G';
const char BLACK = 'B';

// Function to print the stack contents
void printStack(const stack<int>& s) {
    stack<int> temp = s; // Create a temporary copy of the stack to print it
    cout << "Current stack: ";
    if (temp.empty()) {
        cout << "Empty";
    } else {
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
    }
    cout << endl;
}

// Function to print the current DFS order
void printDfsOrder(const vector<int>& dfs_order) {
    cout << "Current DFS order: ";
    for (int vertex : dfs_order) {
        cout << vertex << " ";
    }
    cout << endl;
}

// Perform DFS traversal using a stack
vector<int> dfs(const vector<vector<int>>& adjacency_list, int start_vertex) {
    int num_vertices = adjacency_list.size(); // Number of vertices in the graph
    vector<char> color(num_vertices, WHITE); // Vector to track node colors
    vector<int> dfs_order; // Vector to store the DFS traversal order

    stack<int> vertex_stack; // Stack to hold the vertices to be visited
    vertex_stack.push(start_vertex); // Add the starting vertex to the stack

    while (!vertex_stack.empty()) {
        int current_vertex = vertex_stack.top(); // Get the top vertex from the stack
        vertex_stack.pop(); // Remove the vertex from the stack

        // Check the color of the vertex
        if (color[current_vertex] == WHITE) {
            // Process the vertex
            cout << "Processing vertex: " << current_vertex << endl;

            // Mark the vertex as being processed
            color[current_vertex] = GRAY;

            // Add the vertex to the traversal order
            dfs_order.push_back(current_vertex);

            // Push the vertex onto the stack as a marker for processing
            vertex_stack.push(current_vertex);

            // Add all the unvisited neighbors to the stack
            for (int neighbor_vertex : adjacency_list[current_vertex]) {
                if (color[neighbor_vertex] == WHITE) {
                    // Print the neighbor being added to the stack
                    cout << "Adding neighbor to stack: " << neighbor_vertex << endl;

                    vertex_stack.push(neighbor_vertex);
                }
            }
        } else if (color[current_vertex] == GRAY) {
            // Mark the vertex as processed
            color[current_vertex] = BLACK;
        }

        // Print the current state of the colors
        cout << "Current colors: ";
        for (int i = 0; i < num_vertices; ++i) {
            cout << i << ": ";
            switch (color[i]) {
                case WHITE: cout << "W "; break;
                case GRAY: cout << "G "; break;
                case BLACK: cout << "B "; break;
            }
        }
        cout << endl;

        // Print the current state of the stack
        printStack(vertex_stack);

        // Print the current DFS order
        printDfsOrder(dfs_order);

        cout << endl;
    }

    return dfs_order;
}

int main() {
    // Create an adjacency list for the graph as described
    vector<vector<int>> adjacency_list = {
        {7, 4},      // Vertex 0 is connected to 7 and 4
        {4},         // Vertex 1 is connected to 4
        {4, 6, 3},   // Vertex 2 is connected to 4, 6, and 3
        {2, 6, 7, 5},// Vertex 3 is connected to 2, 6, 7, and 5
        {1, 2, 0, 5},// Vertex 4 is connected to 1, 2, 0, and 5
        {4, 3},      // Vertex 5 is connected to 4 and 3
        {2, 3},      // Vertex 6 is connected to 2 and 3
        {3, 0}       // Vertex 7 is connected to 3 and 0
    };

    // Perform a DFS search starting from vertex 3
    vector<int> dfs_order = dfs(adjacency_list, 3);

    // Print the final traversal order
    cout << "DFS traversal order: ";
    for (int vertex : dfs_order) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
