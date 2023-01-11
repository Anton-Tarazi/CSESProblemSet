#include <bits/stdc++.h>

using namespace std;

int topo_num;

enum class TopoState {
    NOT_PROCESSED,
    PROCESSING,
    COMPLETED
};

bool topo_dfs(int node, vector<vector<int>> &graph,
              vector<TopoState> &processed, vector<int> &ordering) {

    if (processed[node] != TopoState::NOT_PROCESSED) {
        return processed[node] == TopoState::COMPLETED;
    }

    processed[node] = TopoState::PROCESSING;

    for (int next: graph[node]) {
        if (!topo_dfs(next, graph, processed, ordering)) {
            return false;
        }
    }

    processed[node] = TopoState::COMPLETED;
    ordering[--topo_num] = node;
    return true;

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

    topo_num = n;
    vector<vector<int>> graph(n + 1);
    vector<int> ordering(n);
    vector<TopoState> processed(n + 1, TopoState::NOT_PROCESSED);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (processed[i] == TopoState::NOT_PROCESSED &&
            !topo_dfs(i, graph, processed, ordering)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int course: ordering) {
        cout << course << " ";
    }
    cout << "\n";


    return 0;
}