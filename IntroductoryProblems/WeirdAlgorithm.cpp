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
    cin >> n;

    while(true) {
        cout << n << " ";
        if (n == 1) break;
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }

    cout << "\n";

    return 0;
}