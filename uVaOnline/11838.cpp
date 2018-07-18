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

int n, m;
vvi arr;
vi dfs_num, dfs_low, visit;
int res, cnt;
vi S;

const int UNVISITED = -1;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = cnt++;
    visit[u] = 1;
    S.push_back(u);
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        if (visit[v] == UNVISITED) {
            tarjanSCC(v);
        }
        if (visit[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_low[u] == dfs_num[u]) {
        res++;
        while (true) {
            int v = S.back();
            // cerr << v << " ";
            // cerr << v << " " << dfs_num[v] << " " << dfs_low[v] << endl;
            visit[v] = 0;
            S.pop_back();
            if (v == u) {
                break;
            }
        }
        // cerr << endl;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        arr = vvi(n+1);
        dfs_num = vi(n+1, 0);
        dfs_low = vi(n+1, 0);
        visit = vi(n+1, UNVISITED);
        FOR(i, 0, m) {
            int u, v, x;
            cin >> u >> v >> x;
            arr[u].push_back(v);
            if (x == 2) {
                arr[v].push_back(u);
            }
        }
        res = 0;
        
        FORE(i, 1, n) {
            if (visit[i] == UNVISITED) {
                cnt = 0;
                tarjanSCC(i);
            }
        }
        // cerr << res << endl;
        if (res == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}