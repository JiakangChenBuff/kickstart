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
#define INF 1e9
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        (void)(freopen((name + ".in").c_str(), "r", stdin) + 1);
        (void)(freopen((name + ".out").c_str(), "w", stdout) + 1);
    }
}

bool s[26];
int m[26];

void solve() {
    string S, F;
    cin >> S >> F;
    forn(i, (ll)F.length()) s[F[i] - 'a'] = 1;
    forn(i, 26) m[i] = INF;
    forn(i, 26) {
        forn(j, 26) {
            if (s[j]) {
                m[i] = min(m[i], (int)min(abs(i - j), -abs(i - j) + 26));
            }
        }
    }
    int ans = 0;
    forn(i, (ll)S.length()) ans += m[S[i] - 'a'];
    cout << ans << ln;
    memset(s, 0, sizeof(s));
    memset(m, 0, sizeof(m));
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