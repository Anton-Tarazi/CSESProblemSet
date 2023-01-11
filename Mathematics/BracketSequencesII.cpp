#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

long long power(long long a, int b) {
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

long long factorial(int x) {
    long long result = 1;
    for (int i = 1; i <= x; i++) {
        result = (result * i) % MOD;
    }

    return (int) result;
}


long long binomial_coefficient(int a, int b) {
    if (b > a) return 0;

    long long numerator = factorial(a);
    long long denominator = factorial(b) * factorial(a - b) % MOD;
    return numerator * inverse(denominator) % MOD;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    string s;

    cin >> n >> s;
    if (n % 2 == 1) {
        cout << "0\n";
        return 0;
    }

    int half = n / 2;
    int k = (int) s.length();

    int left = 0;
    int right = 0;
    for (char c: s) {
        if (c == '(') left++;
        else right++;

        if (right > left || left > half) {
            cout << "0\n";
            return 0;
        }
    }

    int need = n - k;
    int need_left = half - left;
    int need_right = half - right;
    int diff = need_right - need_left;


    long long total_options = binomial_coefficient(need, need_left);
    long long invalid_options = binomial_coefficient(need, need_left + diff + 1);
    long long ans = (total_options - invalid_options + MOD) % MOD;

    cout << ans << "\n";


    return 0;
}