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

    int total = 0;
    unordered_set<int> seen;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!seen.count(x)) {
            total++;
        }
        seen.insert(x);
    }

    cout << total << "\n";

    return 0;
}