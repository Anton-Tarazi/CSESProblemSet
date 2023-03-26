#include <bits/stdc++.h>

using namespace std;

#define NOT(x) ((x) > n ? (x) - n : (x) + n)


void dfs_topo(int node, int *topo_num, vector<vector<int>> &graph, vector<int> &topo_order, vector<int> &visited) {
    if (visited[node]) return;

    visited[node] = true;

    for (int neighbor: graph[node]) {
        dfs_topo(neighbor, topo_num, graph, topo_order, visited);
    }

    topo_order[*topo_num] = node;
    (*topo_num)--;

}

bool dfs_scc(int node, int scc_num, vector<vector<int>> &graph,
             vector<int> &scc, vector<char> &values, int n) {

    if (scc[NOT(node)] == scc_num) {
        return false;
    }

    scc[node] = scc_num;
    if (node <= n) {
        values[node] = '-';
    } else {
        values[node - n] = '+';
    }

    for (int neighbor: graph[node]) {
        if (!scc[neighbor] && !dfs_scc(neighbor, scc_num, graph, scc, values, n)) {
                return false;
        }
    }

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
    char a_plus, b_plus;

    cin >> m >> n;

    vector<vector<int>> graph(2 * n + 1), reversed_graph(2 * n + 1);
    vector<int> topo_order(2 * n + 1), scc(2 * n + 1), visited(2 * n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a_plus >> a >> b_plus >> b;
        if (a_plus == '-') a = NOT(a);
        if (b_plus == '-') b = NOT(b);

        graph[NOT(a)].push_back(b);
        reversed_graph[b].push_back(NOT(a));

        graph[NOT(b)].push_back(a);
        reversed_graph[a].push_back(NOT(b));
    }

    int topo_num = 2 * n;
    for (int i = 1; i <= 2 * n; i++) {
        dfs_topo(i, &topo_num, reversed_graph, topo_order, visited);
    }

    vector<char> values(n + 1);

    int scc_num = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int topping = topo_order[i];
        if (!scc[topping]) {
            scc_num++;
            if (!dfs_scc(topping, scc_num, graph, scc, values, n)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << values[i] << " ";
    }
    cout << "\n";

    return 0;
}