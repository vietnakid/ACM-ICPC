#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1e9+7
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m;
vvii arr;
vvi check;
vi d;
vi isFree;

void dijkstra() {
    while (true) {
        int u = -1;
        int mx = INF;
        FOR(i, 0, n) {
            if (isFree[i] && d[i] < mx) {
                u = i;
                mx = d[i];
            }
        }
        if (u == -1) break;
        isFree[u] = false;
        FOR(i, 0, arr[u].size()) {
            int v = arr[u][i].first;
            int l = arr[u][i].second;
            if (isFree[v] && d[v] > d[u] + l) {
                d[v] = d[u] + l;
            }
        }
    }
}

void findPath(int u) {
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i].first;
        int l = arr[u][i].second;
        
        if (!check[u][i] && d[u] == d[v] + l) {
            check[u][i] = true;
            // cerr << u  << " " << v << " " << l << endl;
            findPath(v);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> m;

    arr = vvii(n);
    check = vvi(n);
    d = vi(n, INF);
    isFree = vi(n, true);

    FOR(i, 0, m) {
        int u, v, l;
        cin >> u >> v >> l;
        arr[u].push_back({v, l});
        arr[v].push_back({u, l});

        check[u].push_back(false);
        check[v].push_back(false);
    }

    d[0] = 0;
    dijkstra();
    
    findPath(n-1);

    int res = 0;
    FOR(u, 0, n) {
        FOR(i, 0, check[u].size()) {
            if (check[u][i]) {
                res += arr[u][i].second;
            }
        }
    }
    cout << res*2 << endl;
    return 0;
}