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
    scanf("%d", &n);
    int a[30];
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    bool alice = true;
    int ans[] = {0, 0};
    for (int i = n - 1; i >= 0; --i) {
        if (alice) {
            ans[0] += a[i];
        } else {
            ans[1] += a[i];
        }
        alice = !alice;
    }

    printf("%d %d\n", ans[0], ans[1]);
    
    return 0;
}
