#include <iostream>
#include <algorithm>

using namespace std;

int a[200005];

int N, M;

int ans(int x) {
    return lower_bound(a, a + N, x + 1) - a;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a + N);
    
    int x;
    cin >> x;

    cout << ans(x);
    for (int i = 1; i < M; ++i) {
        cin >> x;
        cout << ' ' << ans(x);
    }

    cout << '\n';
    return 0;
}
