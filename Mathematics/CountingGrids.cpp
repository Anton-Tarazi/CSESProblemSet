#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

long long power(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return result;
}

long long inverse(long long a) {
    return power(a, MOD - 2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    long long n;
    cin >> n;

    long long area = (n * n) % (MOD - 1);
    long long half_area = n * (n / 2) % (MOD - 1);
    if (n % 2 == 1) {
        half_area = (half_area + n / 2 + 1) % (MOD - 1);
    }
    long long quarter_area = (n / 2) * (n / 2) % (MOD - 1);
    if (n % 2 == 1) {
        quarter_area = (quarter_area + n / 2 + 1) % (MOD - 1);
    }

    long long null_rotation = power(2, area);
    long long rotation_180 = power(2, half_area);
    long long rotation_90 = power(2, quarter_area);

    long long stabilizer_sum =
            (null_rotation + rotation_180 + 2 * rotation_90) % MOD;
    long long ans = stabilizer_sum * inverse(4) % MOD;

    cout << ans << "\n";


    return 0;
}