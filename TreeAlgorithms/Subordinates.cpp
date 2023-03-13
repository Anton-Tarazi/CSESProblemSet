#include <bits/stdc++.h>

using namespace std;


int dfs(int node, vector<vector<int>> &graph, vector<int> &counts) {

    int count = 0;
    for (int sub: graph[node]) {
        count += 1 + dfs(sub, graph, counts);
    }

    return counts[node] = count;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, boss;
    cin >> n;

    vector<vector<int>> subordinates(n + 1);
    vector<int> num_subordinates(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> boss;
        subordinates[boss].push_back(i);
    }

    dfs(1, subordinates, num_subordinates);

    for (int i = 1; i <= n; i++) {
        cout << num_subordinates[i] << " ";
    }
    cout << "\n";


    return 0;
}