#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>> &graph, int node, int step, vector<int> &visited) {
    if (visited[node] == -1) {
        return -1;
    } else if (visited[node] > 0) {
        int delta = step - visited[node];
        cout << delta + 1 << "\n";
        cout << node << " ";

        visited[node] = -1;
        return delta;
    }


    visited[node] = step;

    int res;
    for (int neighbor: graph[node]) {
        res = dfs(graph, neighbor, step + 1, visited);
        if (res > 0) {
            cout << node << " ";
            visited[node] = -1;
            return res - 1;

        } else if (res == 0) {
            visited[node] = -1;
            return 0;
        }
    }

    visited[node] = -1;
    return -1;

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

    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, 0);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0 && dfs(graph, i, 1, visited) >= 0) {
            cout << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";


    return 0;
}