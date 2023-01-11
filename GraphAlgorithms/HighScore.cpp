#include <bits/stdc++.h>

using namespace std;


#define INF 1e18

typedef tuple<int, int, long long> edge;

void dfs(int node, vector<vector<int>> &graph, vector<int> &visited) {
    if (visited[node] & 1) {
        return;
    }

    visited[node] |= 1;

    for (int neighbor: graph[node]) {
        dfs(neighbor, graph, visited);
    }
}

void reverse_dfs(int node, vector<vector<int>> &graph, vector<int> &visited) {
    if (visited[node] & 2) {
        return;
    }

    visited[node] |= 2;

    for (int neighbor: graph[node]) {
        reverse_dfs(neighbor, graph, visited);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int m, n, a, b;
    long long x;
    cin >> n >> m;

    vector<edge> edges(m);
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> reverse_graph(n + 1);

    vector<int> visited(n + 1, 0);


    for (int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        edges[i] = {a, b, -x};
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }

    dfs(1, graph, visited);
    reverse_dfs(n, reverse_graph, visited);

    vector<long long> distances(n + 1, INF);
    distances[1] = 0;

    bool stable = false;
    for (int i = 0; i < n && !stable; i++) {

        stable = true;
        for (auto &e: edges) {
            tie(a, b, x) = e;
            if (distances[a] + x < distances[b]) {
                distances[b] = distances[a] + x;
                stable = false;

                if (i == n - 1 && visited[b] == 3) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }

    }

    cout << -distances[n] << "\n";


    return 0;
}