#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 2e5;
int tree[MAX_N + 1];
constexpr int MOD = 1e9 + 7;

int sum(int k) {
    int s = 0;
    while (k >= 1) {
        s = (s + tree[k]) % MOD;
        k -= k & -k;
    }
    return s;
}

void add(int k, int x) {
    while (k <= MAX_N) {
        tree[k] = (tree[k] + x) % MOD;
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

    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> indices;

    long long count = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums[i] = x;
        indices[x] = 0;
    }

    int index = 2;
    for (auto &num: indices) {
        num.second = index++;
    }


    for (int x: nums) {
        int ind = indices[x];
        int total_smaller = sum(ind - 1);
        add(ind, total_smaller + 1);
        count = (count + total_smaller + 1) % MOD;

    }

    cout << count << "\n";


    return 0;
}