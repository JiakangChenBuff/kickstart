#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
struct Node {
    int c;
    Node *next, *prev;
    Node(int a) : c(a), next(nullptr), prev(nullptr) {}
    Node(int a, Node *b, Node *c) : c(a), next(b), prev(c) {}
};

vector<queue<Node*> > qs(10, queue<Node*>());

void solve() {
    int N, total = 0;
    cin >> N;
    string s;
    cin >> s;
    vector<Node> arr;
    forn(i, N) {
        Node n(s[i] - '0');
        arr.pb(n);
    }
    forn(i, N) {
        if (i != N - 1) {
            arr[i].next = &arr[i + 1];
            if ((arr[i].c + 1) % 10 == arr[i + 1].c) {
                qs[arr[i].c].push(&arr[i]);
                total++;
            }
        }
        if (i != 0) arr[i].prev = &arr[i - 1];
    }
    Node *st = &arr[0];
    while (total > 0) {
        forn(i, 10) {
            forn(j, qs[i].size()) {
                Node* cur = qs[i].front();
                total--;
                qs[i].pop();
                if (cur->next != nullptr) {
                    Node* nxt = cur->next;
                    Node n(cur->c + 2);
                    if (cur->prev != nullptr) {
                        n.prev = cur->prev;
                        cur->prev = nullptr;
                    }
                    if (nxt->next != nullptr) {
                        n.next = nxt->next;
                        nxt->next = nullptr;
                    }
                    qs[i].push(&n);
                    st = &n;
                    total++;
                }
            }
        }
    }
    while (st->prev != nullptr) {
        st = st->prev;
    }
    string ans;
    while (st != nullptr) {
        ans += to_string(st->c);
        st = st->next;
    }
    cout << ans << ln;
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}