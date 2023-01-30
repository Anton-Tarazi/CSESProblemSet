#include <bits/stdc++.h>

using namespace std;


void decrement(int k, int x, vector<int> &tree, int n) {
    k += n;
    tree[k] -= x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = max(tree[2 * k], tree[2 * k + 1]);
    }

}


int earliest_greater(int pos, int target, vector<int> &tree, int size) {
    if (pos >= size && pos < 2 * size) {
        if (tree[pos] >= target)
            return pos - size;
        return -1;
    }

    if (tree[2 * pos] >= target) {
        return earliest_greater(2 * pos, target, tree, size);
    } else if (tree[2 * pos + 1] >= target) {
        return earliest_greater(2 * pos + 1, target, tree, size);
    }

    return -1;

}


int fill(int pos, vector<int> &tree, int size) {
    if (pos >= size && pos < 2 * size) return tree[pos];

    return tree[pos] = max(fill(2 * pos, tree, size),
                           fill(2 * pos + 1, tree, size));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    int pow2 = (n & (n - 1)) == 0 ? n : 1 << (32 - __builtin_clz(n));
    vector<int> tree(2 * pow2);
    for (int i = 0; i < n; i++) {
        cin >> tree[i + pow2];
    }

    fill(1, tree, pow2);

    int r;
    for (int i = 0; i < m; i++) {
        cin >> r;
        int h = earliest_greater(1, r, tree, pow2);
        cout << h + 1 << " ";
        if (h > -1)
            decrement(h, r, tree, pow2);

    }
    cout << "\n";



    return 0;
}