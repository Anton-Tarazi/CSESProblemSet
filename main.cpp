#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e7;

void dfs(int node, int pred, vector<vector<int>> &tree, vector<int> &values, vector<vector<int>> &dp) {

    for (int neighbor: tree[node]) {
        if (neighbor != pred)
            dfs(neighbor, node, tree, values, dp);
    }


    for (int val = 1; val <= 10000; val++) {

        int cost = val == values[node] ? 0 : val;

        for (int neighbor: tree[node]) {

            if (neighbor == pred)continue;

            int min_neighbor_cost = INF;
            for (int neighbor_val = 1; neighbor_val <= 10000; neighbor_val++) {
                if (gcd(val, neighbor_val) > 1) {
                    min_neighbor_cost = min(min_neighbor_cost, dp[neighbor][neighbor_val]);
                }
            }

            cost += min_neighbor_cost;

        }

        dp[node][val] = cost;

    }



}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> values(n + 1);
    vector<vector<int>> tree(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }


    vector<vector<int>> dp(n + 1, vector<int> (10001, INF));

    dfs(1, -1, tree, values, dp);

    int min_val = INF;
    for (int i = 1; i <= 10000; i++) {
        min_val = min(min_val, dp[1][i]);
    }
    cout << min_val << endl;


    return 0;
}