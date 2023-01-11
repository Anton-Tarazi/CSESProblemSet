#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int t;
    long long a, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;

        if (2 * a >= b && 2 * b >= a && (a + b) % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


    return 0;
}