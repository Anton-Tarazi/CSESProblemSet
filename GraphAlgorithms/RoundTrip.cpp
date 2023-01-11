#include <bits/stdc++.h>

using namespace std;

int dfs(int node, int step, vector<vector<int>> &graph, vector<int> &visited) {

    if (visited[node] != 0) {
        int delta = step - visited[node];
        if (delta >= 3) {
            cout << delta + 1 << "\n";
            cout << node << " ";
            return delta;
        }

        return -1;
    }

    visited[node] = step;

    int res;
    for (int neighbor: graph[node]) {
        res = dfs(neighbor, step + 1, graph, visited);
        if (res >= 0) {
            if (res > 0) {
                cout << node << " ";
                return res - 1;
            }

            return 0;
        }
    }

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
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, 1, graph, visited) >= 0) {
            cout << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";


    return 0;
}