#include <bits/stdc++.h>

using namespace std;

enum class status {
    UNEXPLORED, EXPLORING, CYCLE_START, IN_CYCLE, NOT_CYCLE
};

typedef pair<status, int>  planet_data;
#define STATUS first
#define DATA second

planet_data dfs(int node, int step, vector<int> &graph,
                vector<planet_data> &visited) {

    if (visited[node].STATUS == status::EXPLORING) {
        int cycle_length = step - visited[node].DATA;
        visited[node].STATUS = status::CYCLE_START;
        return {status::IN_CYCLE, cycle_length};

    } else if (visited[node].STATUS == status::IN_CYCLE ||
        visited[node].STATUS == status::NOT_CYCLE) {
        return {status::NOT_CYCLE, visited[node].DATA};
    }

    visited[node] = {status::EXPLORING, step};
    auto result = dfs(graph[node], step + 1, graph, visited);
    if (result.STATUS == status::IN_CYCLE) {
        visited[node].DATA = result.DATA;
        if (visited[node].STATUS == status::CYCLE_START) {
            visited[node].STATUS = status::IN_CYCLE;
            return {status::NOT_CYCLE, result.DATA};
        } else {
            visited[node].STATUS = status::IN_CYCLE;
            return {status::IN_CYCLE, result.DATA};
        }
    } else {
        visited[node] = {status::NOT_CYCLE, result.DATA + 1};
        return visited[node];
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

    vector<planet_data> visited(n + 1, {status::UNEXPLORED, -1});

    for (int i = 1; i <= n; i++) {
        if (visited[i].STATUS == status::UNEXPLORED) {
            dfs(i, 1, successor, visited);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << visited[i].DATA << " ";
    }
    cout << "\n";


    return 0;
}