#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cerr << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        (void)(freopen((name + ".in").c_str(), "r", stdin) + 1);
        (void)(freopen((name + ".out").c_str(), "w", stdout) + 1);
    }
}

void solve() {
    int N;
    cin >> N;
    string P;
    cin >> P;
    vv32 arr(3, v32(N, 0));
    forn(i, (ll)P.length()) {
        switch (P[i]) {
            case 'R':
                arr[0][i] = 1;
                break;
            case 'Y':
                arr[1][i] = 1;
                break;
            case 'B':
                arr[2][i] = 1;
                break;
            case 'O':
                arr[0][i] = arr[1][i] = 1;
                break;
            case 'P':
                arr[0][i] = arr[2][i] = 1;
                break;
            case 'G':
                arr[1][i] = arr[2][i] = 1;
                break;
            case 'A':
                arr[0][i] = arr[1][i] = arr[2][i] = 1;
                break;
        }
    }
    int ans = 0;
    forn(i, 3) {
        forn(j, N) {
            if (arr[i][j] && (j == 0 || !arr[i][j - 1])) ans++;
        }
    }
    cout << ans << ln;
}

int main() {
    setIO();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}