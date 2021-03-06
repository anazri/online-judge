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

    int y;
    scanf(" %d", &y);
    int m = 3;
    int year = 2018;
    while (year < y) {
        m += 26;
        while (m >= 12) {
            m -= 12;
            ++year;
        }
    }

    printf("%s\n", y == year ? "yes" : "no");

    return 0;
}
