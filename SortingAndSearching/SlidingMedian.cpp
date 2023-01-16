#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, k, x;
    cin >> n >> k;

    multiset<int> max_heap;
    multiset<int> min_heap;
    vector<int> nums(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> x;
        nums[i] = x;

        if (min_heap.size() == max_heap.size()) {
            min_heap.insert(x);
            auto bottom = min_heap.begin();
            min_heap.erase(bottom);
            max_heap.insert(*bottom);
        } else {
            max_heap.insert(x);
            auto top = --max_heap.end();
            max_heap.erase(top);
            min_heap.insert(*top);
        }

        if (i >= k) {
            int med = *--max_heap.end();
            cout << med << " ";

            int to_delete = nums[i - k + 1];
            if (to_delete > med) {
                min_heap.erase(min_heap.find(to_delete));
                if (min_heap.size() < max_heap.size() - 1) {
                    auto top = --max_heap.end();
                    max_heap.erase(top);
                    min_heap.insert(*top);
                }
            } else {
                max_heap.erase(max_heap.find(to_delete));
                if (max_heap.size() < min_heap.size()) {
                    auto bottom = min_heap.begin();
                    min_heap.erase(bottom);
                    max_heap.insert(*bottom);
                }
            }
        }

    }

    cout << "\n";


    return 0;
}