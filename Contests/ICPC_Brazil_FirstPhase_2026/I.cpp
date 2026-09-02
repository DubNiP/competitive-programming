#include <bits/stdc++.h>

#define int long long

#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define endl "\n"

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int, int>;
using vvi = vector<vector<int>>;

const int INF = 2e18;
const int MOD = 1e9+7ll;


struct DSU {
 private:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;
    unordered_map<int, int> group_size;
    unordered_map<int, ii> time_duration;
    unordered_map<int, bool> accepted;
 public:
    DSU(vector<ii>& p) {
        for (auto [pi, gs] : p) {
            parent[pi] = pi;
            size[pi] = 1ll;
            group_size[pi] = gs;
        }
    }
    void set_time_duration(int pi, int ai, int ti) {
        pi = find(pi);
        accepted[pi] = true;
        time_duration[pi] = {ai, ti};
    }
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (size[u] > size[v]) {
            swap(u, v);
        }
        size[v] += size[u];
        group_size[v] += group_size[u];
        parent[u] = v;
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    multiset<tuple<int, bool, int, int>> components() {
        multiset<tuple<int, bool, int, int>> events;
        for (auto [pi, ppi] : parent) {
            if (pi != ppi) continue;
            if (!accepted[pi]) continue;
            events.emplace(time_duration[pi].first, true, group_size[pi], time_duration[pi].second);
        }
        return events;
    }
};

void solve(){
    int f, n;
    cin >> f >> n;
    vector<ii> people;
    for (int i = 0; i < n; i++) {
        int ki, pi;
        cin >> ki >> pi;
        people.emplace_back(ki, pi);
    }
    DSU d(people);
    vector<tuple<int, int, int>> accepts;
    for (int i = 0; i < n; i++) {
        char type;
        cin >> type;
        if (type == 'A') {
            int ai, ti;
            cin >> ai >> ti;
            accepts.emplace_back(people[i].first, ai, ti);
        } else if (type == 'D') {

        } else {
            int ki;
            cin >> ki;
            d.join(people[i].first, ki);
        }
    }
    for (auto [pi, ai, ti] : accepts) {
        d.set_time_duration(pi, ai, ti);
    }
    multiset<tuple<int, bool, int, int>> events = d.components();
    int ans = 0ll;
    int current_seats = 0ll;
    while (!events.empty()) {
        ans = max(ans, current_seats);
        auto [time, is_entry, group_size, duration] = *events.begin();
        events.erase(events.begin());
        if (is_entry) {
            current_seats += group_size;
            events.emplace(time+duration, false, group_size, -1);
        } else {
            current_seats -= group_size;
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

