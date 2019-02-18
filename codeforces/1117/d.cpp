#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

// saketh-are
template<typename T>
struct matrix {
    int N;
    vector<T> dat;

    matrix<T> (int _N, T fill = T(0), T diag = T(0)) {
        N = _N;
        dat.resize(N * N, fill);

        for (int i = 0; i < N; i++)
            (*this)(i, i) = diag;
    }

    T& operator()(int i, int j) {
        assert(0 <= i and i < N);
        assert(0 <= j and j < N);
        return dat[N * i + j];
    }

    matrix<T> operator*(matrix<T> &b) {
        matrix<T> r(N);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    r(i, j) = r(i, j) + (*this)(i, k) * b(k, j);

        return r;
    }

    vector<T> operator*(vector<T> &v) {
        vector<T> r(N, T(0));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                r[i] = r[i] + (*this)(i, j) * v[j];
            }
        }

        return r;
    }

    matrix<T> pow(ll expo) {
        if(!expo) return matrix<T>(N, T(0), T(1));
        matrix<T> r = (*this * *this).pow(expo/2);
        return (expo&1) ? (r * *this) : r;
    }

    friend ostream& operator<<(ostream &os, matrix<T> &m) {
        os << "{";
        for (int i = 0; i < m.N; i++) {
            if(i) os << "},\n ";
            os << "{";
            for (int j = 0; j < m.N; j++) {
                if(j) os << ", ";
                os << setw(00) << m(i, j) << setw(0);
            }
        }
        return os << "}}";
    }
};

constexpr int MOD = 1e9 + 7;
struct mll {
    ll val;
    explicit mll(ll _val = 0) {
        val = _val % MOD;
        if (val < 0) val += MOD;
    }

    bool operator==(const mll& other) const {
        return val == other.val;
    }

    mll operator+(const mll &o) {
        return mll((val + o.val) % MOD);
    }

    mll operator*(const mll &o) {
        return mll((val * o.val) % MOD);
    }

    friend ostream& operator<<(ostream &os, mll &m) {
        return os << m.val;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    int m;
    cin >> n >> m;
    // dp[i] = number of ways to make i gems
    // dp[i] = dp[i - 1] + dp[i - m]
    // make a m x m matrix and exponentiate???
    if (n < m) {
        cout << "1" << '\n';
        return 0;
    }

    matrix<mll> mat(m, mll(0), mll(0));
    for (int i = 0; i + 1 < m; ++i) {
        mat(i, i + 1) = mll(1);
    }
    mat(m - 1, 0) = mll(1);
    mat(m - 1, m - 1) = mll(1);

    matrix<mll> e = mat.pow(n - m + 1);

    mll res(0);
    for (int i = 0; i < m; ++i) {
        res = res + e(i, m - 1);
    }

    cout << res << '\n';

    return 0;
}
