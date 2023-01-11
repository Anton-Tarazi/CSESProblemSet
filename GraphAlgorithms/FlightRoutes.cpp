#include <bits/stdc++.h>

using namespace std;

typedef pair<int, long long> edge;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, k, a, b, c;
    cin >> n >> m >> k;

    vector<vector<edge>> graph(n + 1);
    vector<int> count(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    priority_queue<pair<long long, int>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [distance, node] = pq.top(); pq.pop();
        if (count[node] == k) continue;
        count[node]++;

        if (node == n) {
            cout << -distance << " ";
            if (count[n] == k) break;
        }

        for (auto &[neighbor, cost]: graph[node]) {
            pq.push({distance - cost, neighbor});
        }
    }

    cout << "\n";


    return 0;
}