#include <bits/stdc++.h>

using namespace std;

int diameter = 0;

int dfs(int node, int prev, vector<vector<int>> &tree) {

    int maxPath = 0;
    int secondMaxPath = 0;

    for (int neighbor: tree[node]) {
        if (neighbor == prev) continue;

        int path = dfs(neighbor, node, tree);
        if (path > maxPath) {
            secondMaxPath = maxPath;
            maxPath = path;
        } else if (path > secondMaxPath) {
            secondMaxPath = path;
        }

    }

    diameter = max(diameter, maxPath + secondMaxPath);
    return maxPath + 1;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a, b;
    cin >> n;
    vector<vector<int>> tree(n + 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }


    dfs(1, 0, tree);

    cout << diameter << "\n";


    return 0;
}