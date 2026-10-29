
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n, edges;

    cout << "CAMPUS CONNECTIVITY ANALYZER\n";
    cout << "----------------------------\n";

    cout << "Enter number of buildings: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of buildings!\n";
        return 0;
    }

    vector<string> buildings(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter name of building " << i + 1 << ": ";
        cin >> ws;
        getline(cin, buildings[i]);
    }

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<vector<int>> adj(n);

    cout << "Enter number of connections: ";
    cin >> edges;

    if (edges < 0) {
        cout << "Invalid number of connections!\n";
        return 0;
    }

    cout << "\nEnter connections using building numbers:\n";

    for (int i = 0; i < edges; i++) {
        int u, v;

        cout << "Connection " << i + 1
             << " (building1 building2): ";
        cin >> u >> v;

        if (u < 1 || u > n || v < 1 || v > n || u == v) {
            cout << "Invalid connection! Enter again.\n";
            i--;
            continue;
        }

        u--;
        v--;

        if (matrix[u][v] == 0) {
            matrix[u][v] = matrix[v][u] = 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    cout << "\nAdjacency List:\n";

    for (int i = 0; i < n; i++) {
        cout << buildings[i] << " -> ";

        for (int v : adj[i])
            cout << buildings[v] << " ";

        cout << "\n";
    }

    cout << "\nAvailable Buildings:\n";

    for (int i = 0; i < n; i++)
        cout << i + 1 << ". " << buildings[i] << "\n";

    int start;

    cout << "Select starting building number: ";
    cin >> start;

    if (start < 1 || start > n) {
        cout << "Invalid starting building!\n";
        return 0;
    }

    start--;

    // BFS Traversal
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal: ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << buildings[u] << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // DFS Traversal
    vector<bool> visitedDFS(n, false);

    cout << "\nDFS Traversal: ";

    auto dfs = [&](auto&& self, int u) -> void {
        visitedDFS[u] = true;
        cout << buildings[u] << " ";

        for (int v : adj[u]) {
            if (!visitedDFS[v])
                self(self, v);
        }
    };

    dfs(dfs, start);

    cout << "\n";
    return 0;
}
