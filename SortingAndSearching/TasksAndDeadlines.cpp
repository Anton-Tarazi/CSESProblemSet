#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> task;
#define DURATION first
#define DEADLINE second


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a, d;
    cin >> n;
    vector<task> tasks(n);

    for (int i = 0; i < n; i++) {
        cin >> a >> d;
        tasks[i] = {a, d};
    }

    sort(tasks.begin(), tasks.end(), [](task &left, task &right) {
        return left.DURATION < right.DURATION;
    });

    long long reward = 0;
    long long time = 0;
    for (task &t: tasks) {
        time += t.DURATION;
        reward += t.DEADLINE - time;
    }

    cout << reward << "\n";


    return 0;
}