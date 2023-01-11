#include <bits/stdc++.h>

using namespace std;

#define MOD ((int) 1e9 + 7)

int dfs(vector<vector<int>> &graph, int planet, vector<int> &paths) {

    if (paths[planet] != -1) {
        return paths[planet];
    }

    int total = 0;
    for (int next_planet: graph[planet]) {
        total = (total + dfs(graph, next_planet, paths)) % MOD;
    }

    paths[planet] = total;
    return total;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> visited(n, -1);
    visited[n - 1] = 1;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    cout << dfs(graph, 0, visited) << "\n";

    return 0;
}