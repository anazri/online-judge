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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    scanf("%d %d", &n, &k);
    vector<pii> events;
    int a, b;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        ++b;
        events.push_back({b, a});
    }

    sort(begin(events), end(events));
    multiset<int> endings;
    for (int i = 0; i < k; ++i) {
        endings.insert(0);
    }

    int ans = 0;
    for (auto& event : events) {
        tie(b, a) = event;
        auto it = endings.upper_bound(a);
        if (it != begin(endings)) {
            it = prev(it);
            endings.erase(it);
            endings.insert(b);
            ++ans;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
