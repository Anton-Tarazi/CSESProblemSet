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
        if (positions[x - 1] == 0) {
            count++;
        }

        positions[x] = i;
    }

//    for (int j = 1; j <= n; j++) {
//        cout << nums[j] << " ";
//    }
//    cout << "\n";
//    for (int j = 1; j <= n; j++) {
//        cout << positions[j] << " ";
//    }
//    cout << "\n";

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        int left_pos = min(a, b);
        int right_pos = max(a, b);

        volatile int left_num = nums[left_pos];
        volatile int right_num = nums[right_pos];

        bool a_before = prev_before(left_num);
        bool a_after = next_after(left_num);

        bool b_before = prev_before(right_num);
        bool b_after = next_after(right_num);

        swap(positions[left_num], positions[right_num]);
        swap(nums[left_pos], nums[right_pos]);

//        for (int j = 1; j <= n; j++) {
//            cout << nums[j] << " ";
//        }
//        cout << "\n";
//        for (int j = 1; j <= n; j++) {
//            cout << positions[j] << " ";
//        }
//        cout << "\n\n";

        int delta = 0;



        if (!a_before && prev_before(left_num))
            delta--;
        if (a_after && !next_after(left_num))
            delta++;
        if (b_before && !prev_before(right_num))
            delta++;
        if (!b_after && next_after(right_num))
            delta--;

        if (abs(left_num - right_num) == 1) {
            delta /= 2;
        }

        count += delta;


        cout << delta << "\n";




    }




    return 0;
}