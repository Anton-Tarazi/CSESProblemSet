#include <bits/stdc++.h>

using namespace std;


#define MAX_N (int) (1e5 + 1)
#define INF (1e18)


typedef pair<int, int> city;
typedef pair<city, long long> edge;

vector<edge> graph[MAX_N][2];
long long dist[MAX_N][2];
bool processed[MAX_N][2];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int m, n, a, b, c;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a][1].push_back({{b, 1}, c});
        graph[a][1].push_back({{b, 0}, c / 2});
        graph[a][0].push_back({{b, 0}, c});
    }

    for (int i = 1; i <= n; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    dist[1][1] = 0;
    priority_queue<pair<long long, city>> pq;
    pq.push({0, {1, 1}});

    while (!pq.empty()){
        auto [id, coupons] = pq.top().second;
        pq.pop();

        if (processed[id][coupons])
            continue;

        processed[id][coupons] = true;
        for (edge &e: graph[id][coupons]) {
            auto [neighbor, cost] = e;
            auto [neighbor_id, neighbor_coupons] = neighbor;

            if (dist[id][coupons] + cost < dist[neighbor_id][neighbor_coupons]) {
                dist[neighbor_id][neighbor_coupons] = dist[id][coupons] + cost;
                pq.push({-dist[neighbor_id][neighbor_coupons], neighbor});
            }

        }


    }

    cout << dist[n][0] << "\n";


    return 0;
}