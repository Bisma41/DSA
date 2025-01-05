#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// Function to add an edge to the adjacency list
void addEdge(vector<vector<int>> &graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u); // Since the graph is undirected
}

// Function to find all pairs of nodes separated by exactly k edges
void findPairsWithKEdges(vector<vector<int>> &graph, int n, int k) {
    set<pair<int, int>> result; // To store unique pairs

    for (int start = 1; start <= n; ++start) {
        // Perform BFS from the current start node
        vector<bool> visited(n + 1, false);
        queue<pair<int, int>> q; // (current node, distance from start)
        q.push({start, 0});
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();

            // If the distance is exactly k, add the pair to the result
            if (distance == k) {
                if (start < node) {
                    result.insert({start, node});
                } else {
                    result.insert({node, start});
                }
            }

            // Continue BFS if distance is less than k
            if (distance < k) {
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, distance + 1});
                    }
                }
            }
        }
    }

    // Print the result
    for (auto &pair : result) {
        cout << pair.first << " " << pair.second << endl;
    }
}

int main() {
    int n, e, k;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n + 1); // Adjacency list (1-based indexing)

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    cout << "Enter the value of k: ";
    cin >> k;

    cout << "Pairs of nodes separated by exactly " << k << " edges:\n";
    findPairsWithKEdges(graph, n, k);

    return 0;
}

