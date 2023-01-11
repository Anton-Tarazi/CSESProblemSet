#include <bits/stdc++.h>

using namespace std;


void dfs(vector<vector<int>> &graph, int city, vector<int> &visited) {
    if (visited[city]) {
        return;
    }

    visited[city] = 1;
    for (int neighbor: graph[city]) {
        dfs(graph, neighbor, visited);
    }

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
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, 0);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int k = 0;
    vector<int> components;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited);
            k++;
            components.push_back(i);
        }
    }

    cout << k - 1 << "\n";
    for (int i = 1; i < k; i++) {
        cout << components[i - 1] << " " << components[i] << "\n";
    }

    return 0;
}