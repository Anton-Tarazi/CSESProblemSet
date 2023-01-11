#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> to_check;
    vector<int> came_from(n + 1, 0);
    came_from[1] = -1;
    to_check.push(1);

    while (!to_check.empty()) {
        int computer = to_check.front();
        to_check.pop();

        if (computer == n) {
            break;
        }

        for (int neighbor: graph[computer]) {
            if (came_from[neighbor] == 0) {
                came_from[neighbor] = computer;
                to_check.push(neighbor);
            }
        }
    }

    cout << "finished bfs" << endl;

    if (came_from[n] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int current_computer = n;
    vector<int> path;
    while (current_computer != -1) {
        path.push_back(current_computer);
        current_computer = came_from[current_computer];
    }

    cout << path.size() << "\n";
    for (auto c = path.rbegin(); c != path.rend(); c++) {
        cout << *c <<  " ";
    }
    cout << "\n";


    return 0;
}