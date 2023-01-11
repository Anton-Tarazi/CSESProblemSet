#include <bits/stdc++.h>

using namespace std;

int n;
const int STOP = -1;


int dfs(int node, vector<vector<int>> &graph, vector<int> &routes, vector<int> &links) {
    if (node == n) {
        return 1;
    }

    if (routes[node] != 0) {
        return routes[node];
    }

    int max_path = -1;
    for (int neighbor: graph[node]) {
        int path = dfs(neighbor, graph, routes, links);
        if (path > max_path) {
            max_path = path;
            links[node] = neighbor;
        }
    }

    routes[node] = max_path != -1 ? max_path + 1 : -1;
    return routes[node];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int m, a, b;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> max_routes(n + 1);
    vector<int> next_city(n + 1);
    next_city[n] = STOP;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int max_route = dfs(1, graph, max_routes, next_city);
    if (max_route != -1) {
        cout << max_route << "\n";
        int current_city = 1;
        while (current_city != STOP) {
            cout << current_city << " ";
            current_city = next_city[current_city];
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }


    return 0;
}