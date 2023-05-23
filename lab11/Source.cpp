#include <iostream>
#include <climits>

#define V 6

int min_col(int min[], bool visited[]) {
    int mini = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && min[v] < mini) {
            mini = min[v];
            min_index = v;
        }
    }

    return min_index;
}




int main() {
    int graph[V][V] = { { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4},
                        { 1, 0, 5, 0, 4, 0 } };

    int parent[V];
    int min[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        min[i] = INT_MAX;
        visited[i] = false;
    }

    min[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = min_col(min, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < min[v]) {
                parent[v] = u;
                min[v] = graph[u][v];
            }
        }
    }

    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << std::endl;
    }
    return 0;
}