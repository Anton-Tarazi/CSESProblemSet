#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, x, a;
    cin >> n >> x;
    unordered_map<int, int> seen;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (seen.count(x - a)) {
            cout << seen[x - a] << " " << i << "\n";
            return 0;
        }

        seen[a] = i;

    }

    cout << "IMPOSSIBLE\n";

    return 0;
}