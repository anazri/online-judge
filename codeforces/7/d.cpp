#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

using H = ll;
static const H M = INT_MAX;
static const H C = 123891739;

struct K {
    typedef __int128_t H2;
    H x;
    
    K(H x=0) : x(x) {}

    K operator+(const K& o) const { return x + o.x + H(((H2)x + o.x)>>64); }
    K operator*(const K& o) const { return K(x*o.x)+ H(((H2)x * o.x)>>64); }
    H operator-(const K& o) const { K a = *this + ~o.x; return a.x + !~a.x; }
};

// https://github.com/kth-competitive-programming/kactl/blob/master/content/strings/Hashing-codeforces.h
struct hash_interval {
    vector<K> ha, pw;
    hash_interval(const string& s): ha(s.size() + 1), pw(ha) {
        pw[0] = 1;
        for (size_t i = 0; i < s.size(); ++i) {
            ha[i + 1] = ha[i] * C + s[i];
            pw[i + 1] = pw[i] * C;
        }
    }

    // [a, b)
    H hash(int a, int b) const {
        return ha[b] - ha[a] * pw[b - a];
    }
};

// How to flip indexes...
// x + y = n
// n - y

constexpr int MAXN = 5000006;
int n;
int memo[MAXN];
ll score(const hash_interval& forw, const hash_interval& back, int b) {
    if (b <= 0 or forw.hash(0, b) != back.hash(n - b, n)) {
        return 0;
    }

    if (memo[b] != -1)
        return memo[b];

    int len = b >> 1;
    return memo[b] = 1 + score(forw, back, len);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    string t(s);
    reverse(begin(t), end(t));
    n = s.size();

    hash_interval forwards(s);
    hash_interval backwards(t);

    memset(memo, -1, sizeof(memo));
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += score(forwards, backwards, i);
    }

    cout << ans << '\n';

    return 0;
}
