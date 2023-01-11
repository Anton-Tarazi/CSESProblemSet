#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_X = 1e6 + 1;
int divisors[MAX_X];

void init(int num) {
    for (int x = 1; x <= num; x++) {
        for (int u = x; u <= num; u += x) {
            divisors[u]++;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    init(MAX_X);

    int n, x;

    cin >> n;
    while (n --> 0) {
        cin >> x;
        cout << divisors[x] << "\n";

    }


    return 0;
}