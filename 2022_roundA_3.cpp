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

bool valid(string S) {
    bool a = true, b = true, c = true;
    forn(i, 3) if (S[i] != S[5 - i]) a = false;
    forn(i, 2) if (S[i] != S[4 - i]) b = false;
    forsn(i, 1, 3) if (S[i] != S[6 - i]) c = false;
    return !a && !b && !c;
}

void add(queue<string> &wdw, string S, int idx) {
    while (idx < (int)S.length() && S[idx] != '?') idx++;
    if (idx == (int)S.length()) {
        if (valid(S)) wdw.push(S);
        return;
    }
    add(wdw, S.replace(idx, 1, "0"), idx + 1);
    add(wdw, S.replace(idx, 1, "1"), idx + 1);
}

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    if (N == 5) {
        if ((S[0] != '?' && S[4] != '?' && S[0] == S[4]) &&
            (S[1] != '?' && S[3] != '?' && S[1] == S[3])) {
            cout << "IMPOSSIBLE" << ln;
        } else {
            cout << "POSSIBLE" << ln;
        }
        return;
    }
    queue<string> wdw;
    add(wdw, S.substr(0, 6), 0);
    forsn(i, 6, (ll)N) {
        queue<string> nwdw;
        while (!wdw.empty()) {
            string cur = wdw.front();
            wdw.pop();
            string back = cur.substr(1);
            if (S[i] == '?') {
                string nxt = back + "0";
                if (valid(nxt)) nwdw.push(nxt);
                nxt = back + "1";
                if (valid(nxt)) nwdw.push(nxt);
            } else {
                string nxt = cur.substr(1) + S[i];
                if (valid(nxt)) nwdw.push(nxt);
            }
        }
        wdw = nwdw;
    }
    if (sz(wdw) > 0)
        cout << "POSSIBLE" << ln;
    else
        cout << "IMPOSSIBLE" << ln;
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