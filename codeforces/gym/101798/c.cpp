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

    int n;
    scanf(" %d", &n);
    int cap = -1;
    int ans = 0;
    int x;
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &x);
        if (x > cap) {
            ++ans;
            cap = x;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
