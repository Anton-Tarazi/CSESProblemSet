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
    unordered_set<int> seen;

    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!seen.count(x - 1))
            count++;
        seen.insert(x);
    }

    cout << count << "\n";

    return 0;
}