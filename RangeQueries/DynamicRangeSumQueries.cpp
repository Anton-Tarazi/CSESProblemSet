#include <bits/stdc++.h>

using namespace std;


long long sum(int a, int b, vector<long long> &tree, int n) {
    a += n; b += n;
    long long s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += tree[a++];
        if (b % 2 == 0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

void update(int k, int x, vector<long long> &tree, int n) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}


long long fill(int pos, vector<long long> &tree, int size) {
    if (pos >= size && pos < 2 * size) return tree[pos];

    return tree[pos] = fill(2 * pos, tree, size) +
            fill(2 * pos + 1, tree, size);

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

    int pow2 = ((n & (n - 1)) == 0) ? n : (1 << (32 - __builtin_clz(n)));
    vector<long long> tree(2 * pow2, 0);
    for (int i = 0; i < n; i++) {
        cin >> tree[i + n];
    }

    fill(1, tree, n);

    int type;
    for (int i = 0; i < q; i++) {
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            update(k - 1, u, tree, n);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            cout << sum(a - 1, b - 1, tree, n) << "\n";
        }

    }

    
    return 0;
}