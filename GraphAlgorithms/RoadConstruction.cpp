#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE (int) (1e5 + 1)

int parent[MAX_SIZE];
int csize[MAX_SIZE];

int find(int v) {
    return v == parent[v] ? v : parent[v] = find(parent[v]);
}

int uni(int p, int q) {
    int x = find(p);
    int y = find(q);

    if (x == y) return -1;

    if (csize[x] > csize[y]) {
        parent[y] = x;
        csize[x] += csize[y];
        return csize[x];
    } else {
        parent[x] = y;
        csize[y] += csize[x];
        return csize[y];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int m, n, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        csize[i] = 1;
    }

    int max_size = 1;
    int components = n;

    int res;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if ((res = uni(a, b)) != -1) {
            max_size = max(max_size, res);
            components--;
        }

        cout << components << " " << max_size << "\n";

    }


    return 0;
}