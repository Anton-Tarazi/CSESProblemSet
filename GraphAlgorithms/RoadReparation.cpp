#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> edge;


int find(int v, vector<int> &parent) {
    return parent[v] == v ? v : parent[v] = find(parent[v], parent);
}

void link(int v, int w, vector<int> &parent, vector<int> &size) {
    v = find(v, parent);
    w = find(w, parent);

    if (size[v] > size[w]) {
        parent[w] = v;
        size[v] += size[w];
    } else {
        parent[v] = w;
        size[w] += size[v];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, a, b, c;

     cin >> n >> m;
     vector<edge> edges(m);
     vector<int> size(n + 1, 1);
     vector<int> parent(n + 1);
     for (int i = 1; i <= n; i++)
         parent[i] = i;

     for (int i = 0; i < m; i++) {
         cin >> a >> b >> c;
         edges[i] = {c, a, b};
     }
     sort(edges.begin(), edges.end());

     int added = 0;
     long long cost = 0;

     for (edge &e: edges) {
         tie(c, a, b) = e;

         if (find(a, parent) != find(b, parent)) {
             link(a, b, parent, size);
             added++;
             cost += c;
         }

         if (added == n - 1) {
             cout << cost << "\n";
             return 0;
         }
     }

     cout << "IMPOSSIBLE\n";

    return 0;
}