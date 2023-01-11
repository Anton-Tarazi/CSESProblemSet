#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n;
    multiset<int> towers;

    for (int i = 0; i < n; i++) {
        cin >> k;
        auto base = towers.upper_bound(k);
        if (base != towers.end()) {
            towers.erase(base);
        }

        towers.insert(k);
    }

    cout << towers.size() << "\n";

    return 0;
}