#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

ll n, m;
vi state;
vvi arr, parent;
vl cnt;
vi isCal;

void trace(int u) {
    for (auto x : parent[u]) {
        if (!isCal[x]) {
            trace(x);
        }
    }
    isCal[u] = true;
    
    cnt[arr[u][state[u]]] += cnt[u] / 2 + cnt[u] % 2;
    cnt[arr[u][1-state[u]]] += cnt[u] / 2;
    state[u] = (cnt[u] + state[u]) % 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    ll n, m;
    cin >> n >> m;
    state = vi(m+1);
    arr = vvi(m+1, vi(2));
    parent = vvi(m+1);
    FORE(i, 1, m) {
        char c;
        ll l, r;
        cin >> c >> l >> r;
        state[i] = c == 'R';
        arr[i][0] = l;
        arr[i][1] = r;
        parent[l].push_back(i);
        parent[r].push_back(i);
    }
    cnt = vl(m+1, 0);
    cnt[1] = n;
    isCal = vi(m+1, false);

    trace(0);

    FORE(i, 1, m) {
        char c = state[i]==0?'L':'R';
        cout << c;
    }
    cout << endl;
    return 0;
}