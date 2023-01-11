#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    long long n;
    int k;
    cin >> n >> k;
    vector<long long> primes(k);
    for (int i = 0; i < k; i++) {
        cin >> primes[i];
    }

    long long total = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        int ones = 0;
        long long prod = n;
        for (int j = 0; j < k; j++) {
            if (mask & (1 << j)) {
                ones++;
                prod /= primes[j];
            }
        }

        if (ones & 1) {
            total += prod;
        } else {
            total -= prod;
        }

    }

    cout << total << "\n";


    return 0;
}