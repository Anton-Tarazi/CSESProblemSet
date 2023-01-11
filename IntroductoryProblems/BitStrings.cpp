#include <bits/stdc++.h>

using namespace std;

long long binary_exponent(long long base, long long power, long long mod) {
    if (power == 0) return 1;

    long long half = binary_exponent(base, power / 2, mod);
    long long sol = half * half % mod;
    if (power % 2) {
        sol = sol * base % mod;
    }

    return sol;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    cout << binary_exponent(2, n, 1e9 + 7) << "\n";


    return 0;
}