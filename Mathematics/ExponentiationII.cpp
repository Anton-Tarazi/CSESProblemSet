#include <bits/stdc++.h>

using namespace std;


int mod_pow(long long a, int b, int mod) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return (int) result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    const int MOD = 1e9 + 7;

    int n, a, b, c;
    cin >> n;
    while (n --> 0) {
        cin >> a >> b >> c;
        cout << mod_pow(a, mod_pow(b, c, MOD - 1), MOD) << "\n";
    }


    return 0;
}