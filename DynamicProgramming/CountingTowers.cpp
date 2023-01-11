#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1e6;
long long fused[MAX_N + 1];
long long separate[MAX_N + 1];

void init_dp() {
    fused[1] = separate[1] = 1;

    for (int i = 2; i <= MAX_N; i++) {
        fused[i] = ((fused[i - 1] * 2) % MOD + separate[i - 1]) % MOD;
        separate[i] = ((separate[i - 1] * 4) % MOD + fused[i - 1]) % MOD;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    init_dp();

    int t, n;
    cin >> t;
    while (t --> 0) {
        cin >> n;
        cout << (fused[n] + separate[n]) % MOD << "\n";
    }


    return 0;
}