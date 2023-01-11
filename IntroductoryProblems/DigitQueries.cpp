#include <bits/stdc++.h>

using namespace std;


int query(long long x) {

    if (x <= 9)
        return (int) x;

    x--;
    long long len = 1;
    long long to_skip = 9;
    long long base = 1;

    while (to_skip * len <= x) {

        x -= to_skip * len;

        len++;
        to_skip *= 10;
        base *= 10;
    }

    long long ans = base + x / len;
    long long to_remove = len - x % len - 1;
    while (to_remove --> 0)
        ans /= 10;

    return (int) (ans % 10);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int q;
    cin >> q;

    long long k;
    while (q --> 0) {
        cin >> k;
        query(k);
        cout << query(k) << "\n";
    }



    return 0;
}