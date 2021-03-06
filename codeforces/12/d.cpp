#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int INF = 1e9 + 7;
struct BIT {
    int n;
    vi data;
    BIT(int n): n(n) {
        data.assign(n + 1, INF);
    }

    int query(int x) {
        ++x;
        assert(x <= n);
        int res = INF;
        for (; x; x -= (x & -x)) {
            res = min(res, data[x]);
        }

        return res;
    }

    void update(int x, int v) {
        ++x;
        assert(x <= n);
        for (; x <= n; x += (x & -x)) {
            data[x] = min(data[x], v);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // originally we want
    // xi < xj, yi < yj and zi < zj
    // negate everything so i dead if
    // xi > xj, yi > yj and zi > zj
    // process in increasing order of x, do groups
    // need to query for all yj < y, what is min z?
    //
    // given (y, z) is there (y', z') where y' <  y and z' < z

    int n;
    cin >> n;
    vector<tuple<int, int, int>> a; 
    vi xs(n), ys(n), zs(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> ys[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> zs[i];
    }
    for (int i = 0; i < n; ++i) {
        xs[i] = -xs[i];
        ys[i] = -ys[i];
        zs[i] = -zs[i];
        a.emplace_back(xs[i], ys[i], zs[i]);
    }

    sort(all(xs));
    sort(all(ys));
    sort(all(zs));

    sort(all(a));

    int dead = 0;

    BIT b(n);
    vector<pii> stk;
    int last = INF;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        tie(x, y, z) = a[i];
        x = lower_bound(all(xs), x) - begin(xs);
        y = lower_bound(all(ys), y) - begin(ys);
        z = lower_bound(all(zs), z) - begin(zs);

        // cout << "at " << x << " " << y << " " << z << '\n';

        if (x != last) {
            while (!stk.empty()) {
                int u, v;
                tie(u, v) = stk.back();
                stk.pop_back();

                b.update(u, v);
            }
        }

        int v = b.query(y - 1);
        if (v < z) {
            ++dead;
        }

        stk.emplace_back(y, z);
        last = x;
    }

    cout << dead << '\n';
    return 0;
}
