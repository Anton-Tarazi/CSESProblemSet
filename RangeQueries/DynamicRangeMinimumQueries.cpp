#include <bits/stdc++.h>

using namespace std;


int minimum(int a, int b, vector<int> &tree, int n) {
    a += n; b += n;
    int s = INT32_MAX;
    while (a <= b) {
        if (a % 2 == 1) s = min(s, tree[a++]);
        if (b % 2 == 0) s = min(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}


void update(int k, int x, vector<int> &tree, int n) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = min(tree[2 * k], tree[2 * k + 1]);
    }
}


int fill(int pos, vector<int> &tree, int size) {
    if (pos >= size && pos < 2 * size) return tree[pos];

    return tree[pos] = min(fill(2 * pos, tree, size),
                            fill(2 * pos + 1, tree, size));

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

    int pow2 = (n & (n - 1)) == 0 ? n : 1 << (32 - __builtin_clz(n));
    vector<int> tree(2 * pow2);
    for (int i = 0; i < n; i++) {
        cin >> tree[i + pow2];
    }

    fill(1, tree, pow2);

    int type;
    for (int i = 0; i < q; i++) {
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            update(k - 1, u, tree, pow2);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            cout << minimum(a - 1, b - 1, tree, pow2) << "\n";
        }
    }


    return 0;
}