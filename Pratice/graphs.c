#include <stdio.h>

#define MAX_VERTICES 100 // Define a maximum number of vertices allowed

int main() {
    int num_vertices, i, j;

    // Get the number of vertices in the graph from the user
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    // Check for valid input (avoid exceeding maximum)
    if (num_vertices > MAX_VERTICES) {
        printf("Error: Maximum number of vertices allowed is %d\n", MAX_VERTICES);
        return 1; // Exit program with an error code
    }

    // Declare the adjacency matrix with appropriate size
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];

    // Initialize all elements of the matrix to 0 (no edges initially)
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    // Get edge information (assuming undirected graph)
    printf("Enter the edges (source vertex, destination vertex):\n");
    while (1) {
        int source, destination;

        printf("Enter source vertex (-1 to stop): ");
        scanf("%d", &source);

        if (source == -1) {
            break; // Exit loop if user enters -1
        }

        printf("Enter destination vertex: ");
        scanf("%d", &destination);

        // Check for valid vertex indices (within bounds)
        if (source < 0 || source >= num_vertices || destination < 0 || destination >= num_vertices) {
            printf("Error: Invalid vertex index.\n");
            continue; // Skip to the next iteration without adding the edge
        }

        // Add the edge information to the adjacency matrix (undirected graph)
        adj_matrix[source][destination] = 1;
        adj_matrix[destination][source] = 1; // Add for both directions (undirected)
    }

    // Print the adjacency matrix representation of the graph
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    return 0; // Indicate successful program execution
}
