#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE (int) (2e5 + 1)
int n;
int nums[MAX_SIZE];
int positions[MAX_SIZE];

static inline bool prev_before(int p) {
    if (p == 1) return false;
    return positions[p - 1] < positions[p];

}

static inline bool next_after(int p) {
    if (p == n) return false;
    return positions[p + 1] > positions[p];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int m, x, a, b;
    cin >> n >> m;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        nums[i] = x;
        if (positions[x - 1] == 0) count++;

        positions[x] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        int left_pos = min(a, b);
        int right_pos = max(a, b);

        int left_num = nums[left_pos];
        int right_num = nums[right_pos];

        bool left_before = prev_before(left_num);
        bool left_after = next_after(left_num);

        bool right_before = prev_before(right_num);
        bool right_after = next_after(right_num);

        swap(positions[left_num], positions[right_num]);
        swap(nums[left_pos], nums[right_pos]);
        int delta = 0;

        if (!left_before && prev_before(left_num))
            delta--;
        if (left_after && !next_after(left_num))
            delta++;
        if (right_before && !prev_before(right_num))
            delta++;
        if (!right_after && next_after(right_num))
            delta--;

        if (left_num == right_num - 1)
            delta--;
        else  if (left_num == right_num + 1)
            delta++;

        count += delta;
        cout << count << "\n";

    }


    return 0;
}