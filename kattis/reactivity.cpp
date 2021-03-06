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

constexpr int MAXN = 1003;
int n, m;
vector<int> graph[MAXN];
int in_deg[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        in_deg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (in_deg[i] == 0)
            q.push(i);

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (q.size() != 1) {
            res.clear();
            break;
        }
        res.push_back(q.front());
        q.pop();

        for (int v : graph[res.back()]) {
            if (--in_deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (res.size() != n)
        printf("back to the lab\n");
    else {
        for (int x : res)
            printf("%d ", x);
        printf("\n");
    }

    return 0;
}
