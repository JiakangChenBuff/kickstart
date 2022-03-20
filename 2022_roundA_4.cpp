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

ll ps[100005];

void solve() {
    int A, B;
    cin >> A >> B;
    cout << ps[B] - ps[A - 1] << ln;
}

bool works(int x) {
    string xstr = to_string(x);
    int sum = 0;
    int prd = 1;
    forn(i, (ll)xstr.length()) {
        sum += (xstr[i] - '0');
        prd *= (xstr[i] - '0');
    }
    return (prd % sum == 0);
}

int main() {
    setIO();
    ll t;
    cin >> t;
    forsn(i, 1, 100001) {
        ps[i] = ps[i - 1];
        if (works(i)) {
            ps[i]++;
        }
    }
    for (int it = 1; it <= t; it++) {
        cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}