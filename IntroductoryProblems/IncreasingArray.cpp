#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, last, x;
    long long moves = 0;
    cin >> n;
    cin >> last;

    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x >= last) {
            last = x;
        } else {
            moves += last - x;
        }
    }

    cout << moves << "\n";


    return 0;
}