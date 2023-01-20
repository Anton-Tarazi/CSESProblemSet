#include <bits/stdc++.h>

using namespace std;

using Grid = array<int, 9>;

int swaps[12][2] = {{0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7},
                    {5, 8}, {0, 1}, {3, 4}, {6, 7}, {1, 2},
                    {4, 5}, {7, 8}};


void process(Grid &grid, int dist, map<Grid, int> &own_map, vector<Grid> &next_layer) {

    for (auto [x, y]: swaps) {
        swap(grid[x], grid[y]);
        if (!own_map.count(grid)) {
            next_layer.push_back(grid);
            own_map[grid] = dist + 1;
        }
        swap(grid[x], grid[y]);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    array<int, 9> start{};
    array<int, 9> target{};

    for (int i = 0; i < 9; i++) {
        cin >> start[i];
        target[i] = i + 1;
    }


    map<Grid, int> start_map;
    map<Grid, int> target_map;

    vector<Grid> start_layer;
    vector<Grid> target_layer;

    int start_dist = 0;
    int target_dist = 0;

    start_layer.push_back(start);
    start_map[start] = 0;

    target_layer.push_back(target);
    target_map[target] = 0;

    while (!start_layer.empty() || !target_layer.empty()) {

        vector<Grid> new_start;
        for (Grid &grid: start_layer) {

            auto in_target = target_map.find(grid);
            if (in_target != target_map.end()) {
                cout << start_dist + in_target->second << "\n";
                return 0;
            }

            process(grid, start_dist, start_map, new_start);

        }

        vector<Grid> new_target;
        for (Grid &grid: target_layer) {
            process(grid, target_dist, target_map, new_target);
        }

        start_dist++;
        start_layer = std::move(new_start);

        target_dist++;
        target_layer = std::move(new_target);
    }


    return 0;
}