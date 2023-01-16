#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, q, x, a, b;
    cin >> n >> q;

    vector<int> prefix_xor(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        prefix_xor[i] = prefix_xor[i - 1] ^ x;
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << (prefix_xor[b] ^ prefix_xor[a - 1]) << "\n";
    }


    return 0;
}