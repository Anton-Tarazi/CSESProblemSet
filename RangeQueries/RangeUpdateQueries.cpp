#include <bits/stdc++.h>

using namespace std;


long long sum(int k, vector<long long> &tree) {
    long long s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

void add(int k, long long x, vector<long long> &tree, int n) {
    while (k <= n) {
        tree[k] += x;
        k += k & -k;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif


    int n, q;
    cin >> n >> q;
    vector<long long> difference_array(n + 1, 0);

    long long last = 0, x = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        add(i, x - last, difference_array, n);
        last = x;
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            add(a, u, difference_array, n);
            if (b != n) add(b + 1, -u, difference_array, n);
        } else if (type == 2) {
            int k;
            cin >> k;
            cout << sum(k, difference_array) << "\n";
        }
    }


    return 0;
}