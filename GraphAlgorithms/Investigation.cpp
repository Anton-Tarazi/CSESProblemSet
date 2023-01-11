#include <bits/stdc++.h>

using namespace std;

#define INF 1e18
#define MOD (int) (1e9 + 7)


typedef pair<int, long long> edge;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, a, b, c;
    cin >> n >> m;

    vector<vector<edge>> graph(n + 1);
    vector<bool> processed(n + 1, false);
    vector<long long> dist(n + 1, INF);
    vector<int> counts(n + 1, 0);
    vector<int> min_flights(n + 1, 0);
    vector<int> max_flights(n + 1, 0);

    dist[1] = 0;
    counts[1] = 1;
    min_flights[1] = 0;
    max_flights[1] = 0;


    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }


    priority_queue<pair<long long, int>> pq;
    pq.push({0, 1});


    while (!pq.empty()) {
        int city = pq.top().second;
        pq.pop();

        if (processed[city])
            continue;

        processed[city] = true;

        for (edge &e: graph[city]) {
            auto [dest, cost] = e;

            if (dist[city] + cost < dist[dest]) {
                dist[dest] = dist[city] + cost;
                counts[dest] = counts[city];
                max_flights[dest] = max_flights[city] + 1;
                min_flights[dest] = min_flights[city] + 1;

                pq.push({-dist[dest], dest});

            } else if (dist[city] + cost == dist[dest]) {
                counts[dest] = (counts[dest] + counts[city]) % MOD;
                max_flights[dest] = max(max_flights[dest], max_flights[city] + 1);
                min_flights[dest] = min(min_flights[dest], min_flights[city] + 1);
            }

        }

    }


    cout << dist[n] << " ";
    cout << counts[n] << " ";
    cout << min_flights[n] << " ";
    cout << max_flights[n] <<  "\n";


    return 0;
}