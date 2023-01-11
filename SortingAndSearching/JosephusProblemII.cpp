#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, k;
    indexed_set circle;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        circle.insert(i);
    }

    int cur = 0;
    for (int i = n; i >= 1; i--) {
        cur = (cur + k) % i;
        auto x = circle.find_by_order(cur);
        cout << *x << " ";
        circle.erase(x);
    }

    cout << "\n";


    return 0;
}