#include <bits/stdc++.h>

using namespace std;

void dfs_topo(int node, int *topo_num, vector<vector<int>> &graph, vector<int> &topo_order, vector<int> &visited) {
    if (visited[node]) return;

    visited[node] = true;

    for (int neighbor: graph[node]) {
        dfs_topo(neighbor, topo_num, graph, topo_order, visited);
    }

    topo_order[*topo_num] = node;
    (*topo_num)--;
}

void dfs_scc(int node, int scc_num, vector<vector<int>> &graph, vector<int> &scc) {
    if (scc[node]) return;

    scc[node] = scc_num;
    for (int neighbor: graph[node]) {
        dfs_scc(neighbor, scc_num, graph, scc);
    }
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
    vector<int> topo_order(n + 1), scc(n + 1), visited(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        reversed_graph[b].push_back(a);
    }

    int topo_num = n;
    for (int i = 1; i <= n; i++) {
        dfs_topo(i, &topo_num, reversed_graph, topo_order, visited);
    }

    int scc_num = 0;
    for (int i = 1; i <= n; i++) {
        int planet = topo_order[i];
        if (!scc[planet]) {
            scc_num++;
            dfs_scc(planet, scc_num, graph, scc);
        }
    }

    cout << scc_num << "\n";
    for (int i = 1; i <= n; i++) {
        cout << scc[i] << " ";
    }
    cout << "\n";

    return 0;
}