#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 100005;
int SQRTN;
int n, k;
int t[MAXN], a[MAXN];
ll p[MAXN];
ll ans[MAXN];
ll cur = 0;
int ind[MAXN], left_ind[MAXN], right_ind[MAXN];
int freq[3 * MAXN];

struct query {
    int l, r, i;
} queries[MAXN];

bool cmp(const query& a, const query& b) {
    return a.l / SQRTN < b.l / SQRTN || (a.l / SQRTN == b.l / SQRTN and a.r < b.r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", t + i);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    vector<ll> vals;
    vals.push_back(0LL);
    vals.push_back(k);
    vals.push_back(-k);
    p[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
        if (t[i] == 1)
            p[i] = p[i - 1] + a[i];
        else
            p[i] = p[i - 1] - a[i];

        vals.push_back(p[i]);
        vals.push_back(p[i] - k);
        vals.push_back(p[i] + k);
    }

    sort(begin(vals), end(vals));
    vals.erase(unique(begin(vals), end(vals)), end(vals));

    for (int i = 0; i <= n; ++i) {
        ind[i] = lower_bound(begin(vals), end(vals), p[i]) - begin(vals);
        left_ind[i] = lower_bound(begin(vals), end(vals), p[i] - k) - begin(vals);
        right_ind[i] = lower_bound(begin(vals), end(vals), p[i] + k) - begin(vals);
    }

    SQRTN = sqrt(n);

    int q;
    int l, r;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &l, &r);
        --l;
        queries[i] = {l, r, i};
    }

    sort(queries, queries + q, cmp);

    int left_ptr = 0;
    int right_ptr = -1;
    for (int i = 0; i < q; ++i) {
        // printf("%d %d\n", queries[i].l, queries[i].r);
        while (right_ptr < queries[i].r) {
            ++right_ptr;
            cur += freq[left_ind[right_ptr]];
            ++freq[ind[right_ptr]];
        }

        while (right_ptr > queries[i].r) {
            --freq[ind[right_ptr]];
            cur -= freq[left_ind[right_ptr]];
            --right_ptr;
        }

        while (left_ptr < queries[i].l) {
            --freq[ind[left_ptr]];
            cur -= freq[right_ind[left_ptr]];
            ++left_ptr;
        }

        while (left_ptr > queries[i].l) {
            --left_ptr;
            cur += freq[right_ind[left_ptr]];
            ++freq[ind[left_ptr]];
        }

        ans[queries[i].i] = cur;
    }

    for (int i = 0; i < q; ++i) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
