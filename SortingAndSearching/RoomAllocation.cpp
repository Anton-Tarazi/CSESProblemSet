#include <bits/stdc++.h>

using namespace std;

#define TIMES first
#define A first
#define D second
#define GUEST_NUM second

#define FREE first
#define ROOM_NUM second

typedef pair<int, int> room;
typedef pair<int, int> times;
typedef pair<times, int> guest;

struct CompareRoom {
    bool operator()(const room &r1, const room &r2) {
        return r2.FREE < r1.FREE;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a, b;
    cin >> n;
    vector<guest> guests(n);
    vector<int> room_usages(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        guests[i] = guest(times(a, b), i);
    }

    sort(guests.begin(), guests.end());
    priority_queue<room, vector<room>, CompareRoom> rooms;

    int room_num = 0;

    for (guest &g: guests) {

        if (!rooms.empty() && rooms.top().FREE < g.TIMES.A) {
            room r = rooms.top();
            rooms.pop();
            r.FREE = g.TIMES.D;
            rooms.push(r);
            room_usages[g.GUEST_NUM] = r.ROOM_NUM;
        } else {
            room r = {g.TIMES.D, ++room_num};
            rooms.push(r);
            room_usages[g.GUEST_NUM] = r.ROOM_NUM;
        }

    }

    cout << room_num << "\n";
    for (int &r: room_usages) {
        cout << r << " ";
    }
    cout << "\n";

    return 0;
}