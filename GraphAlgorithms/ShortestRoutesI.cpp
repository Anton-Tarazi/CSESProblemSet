#include <bits/stdc++.h>

using namespace std;

#define INF 1e18


struct flight {
    int dest;
    long long cost;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, a, b;
    long long c;
    cin >> n >> m;
    vector<vector<flight>> graph(n + 1);
    vector<long long> dist(n + 1, INF);
    vector<bool> processed(n + 1, false);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    priority_queue<pair<long long, int>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int city = pq.top().second;
        pq.pop();
        if (processed[city]) {
            continue;
        }

        processed[city] = true;

        for (auto &flight: graph[city]) {
            int dest = flight.dest;
            long long cost = flight.cost;

            if (dist[city] + cost < dist[dest]) {
                dist[dest] = dist[city] + cost;
                pq.push({-dist[dest], dest});
            }
        }

    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";


    return 0;
}