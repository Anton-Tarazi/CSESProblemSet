#include <bits/stdc++.h>

using namespace std;

#define INF 1e18
typedef tuple<int, int, long long> edge;


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

    vector<long long> distances(n + 1, INF);
    vector<int> came_from(n + 1, -1);
    vector<edge> edges(m);


    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    int reachable_from_negative_cycle = -1;

    bool stable = false;
    for (int i = 0; i < n && !stable; i++) {
        stable = true;

        for (edge &e: edges) {
            tie(a, b, c) = e;

            if (distances[a] + c < distances[b]) {
                distances[b] = distances[a] + c;
                stable = false;
                came_from[b] = a;

                if (i == n - 1) {
                    reachable_from_negative_cycle = b;
                }
            }
        }
    }

    if (reachable_from_negative_cycle == -1) {
        cout << "NO\n";
        return 0;
    }

    int slow = reachable_from_negative_cycle;
    int fast = reachable_from_negative_cycle;

    do {
        slow = came_from[slow];
        fast = came_from[came_from[fast]];
    } while (slow != fast);

    int cur = slow;
    vector<int> negative_cycle;
    negative_cycle.push_back(cur);
    do {
        cur = came_from[cur];
        negative_cycle.push_back(cur);
    } while (cur != slow);

    reverse(negative_cycle.begin(), negative_cycle.end());
    cout << "YES\n";
    for (int node: negative_cycle) {
        cout << node << " ";
    }
    cout << "\n";


    return 0;
}