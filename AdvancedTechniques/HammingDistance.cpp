#include <bits/stdc++.h>

#ifndef LOCAL
#pragma GCC target("popcnt")
#endif

using namespace std;
constexpr int MAX_N = 1e4 + 1;
int nums[MAX_N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, k;
    string s;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        nums[i] = stoi(s, nullptr, 2);
    }

    int min_distance = k + 1;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            min_distance = min(min_distance, __builtin_popcount(nums[i] ^ nums[j]));
        }
    }

    cout << min_distance << "\n";


    return 0;
}