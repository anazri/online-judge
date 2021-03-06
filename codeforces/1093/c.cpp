#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<ll> b(n);

    int h = n >> 1;
    for (int i = 0; i < h; ++i) {
        cin >> b[i];
        b[n - i - 1] = b[i];
    }

    vector<ll> a(n, 0);
    a[0] = 0;
    a[n - 1] = b[0];
    for (int i = 1; i < h; ++i) {
        int j = n - i - 1;
        ll x = a[i - 1];
        ll y = b[i] - a[j + 1];
        a[i] = max(x, y);
        a[j] = b[i] - a[i];
    }

    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    
    return 0;
}
