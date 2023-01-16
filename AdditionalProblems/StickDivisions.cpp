#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int x, n, d;
    cin >> x >> n;

    priority_queue<int, vector<int>, greater<>> sticks;
    for (int i = 0; i < n; i++) {
        cin >> d;
        sticks.push(d);
    }

    long long cost = 0;
    while (sticks.size() > 1) {
        int s1 = sticks.top();
        sticks.pop();
        int s2 = sticks.top();
        sticks.pop();

        cost += s1 + s2;
        sticks.push(s1 + s2);

    }

    cout << cost << "\n";


    return 0;
}