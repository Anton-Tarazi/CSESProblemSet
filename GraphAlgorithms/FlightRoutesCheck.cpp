#include <bits/stdc++.h>

using namespace std;

int sink_node;

void dfs_topo(int node, vector<vector<int>> &graph, vector<int> &visited, bool topo) {
    if (visited[node]) return;

    visited[node] = true;
    for (int neighbor: graph[node]) {
        dfs_topo(neighbor, graph, visited, topo);
    }

    if (topo)
        sink_node = node;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1), reversed_graph(n + 1);
    vector<int> visited(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        reversed_graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        dfs_topo(i, reversed_graph, visited, true);
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    dfs_topo(sink_node, graph, visited, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO\n";
            cout << sink_node << " " << i << "\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}