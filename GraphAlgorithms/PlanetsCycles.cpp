#include <bits/stdc++.h>

using namespace std;

enum class status {
    UNEXPLORED, EXPLORING, EXPLORED
};

pair<int, int> dfs(int node, int step, vector<int> &graph,
                vector<status> &visited, vector<int> &dist) {

    switch (visited[node]) {
        case status::EXPLORING: {
            int cycle_length = step - dist[node];
            return {cycle_length, -cycle_length + 1};
        }
        case status::EXPLORED:
            return {-1, dist[node]};
        default:
            break;
    }

    visited[node] = status::EXPLORING;
    dist[node] = step;
    auto [cycle_length, cycle_distance] =
            dfs(graph[node], step + 1, graph, visited, dist);
    visited[node] = status::EXPLORED;

    if (cycle_length == -1) {
        dist[node] = cycle_distance + 1;
        return {-1, cycle_distance + 1};
    } else {
        dist[node] = cycle_length;
        if (cycle_distance == 0) {
            return {-1, cycle_length};
        } else {
            return {cycle_length, cycle_distance + 1};
        }

    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> successor(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> successor[i];
    }

    vector<status> visited(n + 1, status::UNEXPLORED);
    vector<int> distances(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (visited[i] == status::UNEXPLORED) {
            dfs(i, 1, successor, visited, distances);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << distances[i] << " ";
    }
    cout << "\n";


    return 0;
}