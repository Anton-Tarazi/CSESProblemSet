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

long long dfs_scc(int node, int scc_num, vector<vector<int>> &graph, vector<int> &scc,
             vector<int> &coins, vector<unordered_set<int>> &meta_graph) {

    long long coin_total = coins[node];

    scc[node] = scc_num;
    for (int neighbor: graph[node]) {
        if (!scc[neighbor]) {
            coin_total += dfs_scc(neighbor, scc_num, graph, scc, coins, meta_graph);
        } else if (scc[neighbor] != scc_num) {
            meta_graph[scc_num].insert(scc[neighbor]);
        }
    }

    return coin_total;
}

long long dfs_meta(int node, vector<unordered_set<int>> &graph, vector<long long> &coins, vector<long long> &dp) {
    if (dp[node]) return dp[node];

    long long best_path = 0;
    for (int neighbor: graph[node]) {
        best_path = max(best_path, dfs_meta(neighbor, graph, coins, dp));
    }
    best_path += coins[node];
    dp[node] = best_path;

    return best_path;
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
    vector<int> coins(n + 1), topo_order(n + 1), scc(n + 1), visited(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        reversed_graph[b].push_back(a);
    }

    int topo_num = n;
    for (int i = 1; i <= n; i++) {
        dfs_topo(i, &topo_num, reversed_graph, topo_order, visited);
    }

    vector<unordered_set<int>> meta_graph(n + 1);
    vector<long long> meta_coins(n + 1), meta_dp(n + 1);

    int scc_num = 0;
    for (int i = 1; i <= n; i++) {
        int node = topo_order[i];
        if (!scc[node]) {
            scc_num++;
            long long coin_total = dfs_scc(node, scc_num, graph, scc, coins, meta_graph);
            meta_coins[scc_num] = coin_total;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= scc_num; i++) {
        long long path = dfs_meta(i, meta_graph, meta_coins, meta_dp);
        ans = max(ans, path);

    }

    cout << ans << "\n";

    return 0;
}