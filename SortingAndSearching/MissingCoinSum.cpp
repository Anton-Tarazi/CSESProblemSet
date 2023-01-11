#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<long long> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());
    long long can_make = 0;

    for (long long c: coins) {
        if (c > can_make + 1) {
            break;
        } else {
            can_make += c;
        }
    }

    cout << can_make + 1 << "\n";


    return 0;
}