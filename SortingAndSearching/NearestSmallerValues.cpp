#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, x;
    cin >> n;
    stack<pair<int, int>> increasing_nums;

    for (int i = 1; i <= n; i++) {
        cin >> x;
        while (!increasing_nums.empty() && increasing_nums.top().second >= x) {
            increasing_nums.pop();
        }

        cout << (increasing_nums.empty() ? 0 : increasing_nums.top().first) << " ";

        increasing_nums.push({i, x});
    }

    cout << "\n";


    return 0;
}