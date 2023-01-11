#include <bits/stdc++.h>

using namespace std;

#define max_students 1e5

vector<vector<int>> graph(max_students + 1);
vector<int> teams(max_students + 1, 0);

bool dfs(int student, int team) {
    if (teams[student] != 0) {
        return teams[student] == team;
    }

    teams[student] = team;
    for (int f: graph[student]) {
        if (!dfs(f, 3 - team)) {
            return false;
        }
    }

    return true;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (teams[i] == 0 && !dfs(i, 1)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << teams[i] << " ";
    }

    cout << "\n";

    return 0;
}