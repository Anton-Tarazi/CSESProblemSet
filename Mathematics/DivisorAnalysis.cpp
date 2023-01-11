#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

static inline long long power(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return result;
}

static inline long long inverse(long long a) {
    return power(a, MOD - 2);
}

static inline long long geometric_sum(int p, int e) {
    long long numerator = power(p, e + 1) - 1;
    long long denominator = inverse(p - 1);

    return numerator * denominator % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, p, e;
    cin >> n;

    long long number_divisors = 1;
    long long sum_divisors = 1;

    long long number = 1;
    long long square_root = 1;
    long long number_divisors_for_exp = 1;

    bool perfect_square = true;

    for (int i = 0; i < n; i++) {
        cin >> p >> e;

        number_divisors = (number_divisors * (e + 1)) % MOD;
        sum_divisors = (sum_divisors * geometric_sum(p, e)) % MOD;


        number = (number * power(p, e)) % MOD;
        square_root = (square_root * power(p, e / 2)) % MOD;

        if (e % 2 == 1 && perfect_square) {
            number_divisors_for_exp = (number_divisors_for_exp * (e + 1) / 2) % (MOD - 1);
            perfect_square = false;
        } else {
            number_divisors_for_exp = (number_divisors_for_exp * (e + 1)) % (MOD - 1);
        }

    }

    long long prod_divisors;
    if (perfect_square) {
        prod_divisors = power(square_root, number_divisors_for_exp);
    } else {
        prod_divisors = power(number, number_divisors_for_exp);
    }

    cout << number_divisors % MOD << " " << sum_divisors << " " << prod_divisors << "\n";


    return 0;
}