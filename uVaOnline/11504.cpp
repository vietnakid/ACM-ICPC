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
vi dfs_num, dfs_low, visit, visitBack, deg;
vvi arr;
int cnt, res, cntSCC;
vi S;
vi belong, brr;

const int UNVISTED = -1;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = cnt++;
    visit[u] = 1;
    S.push_back(u);
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        if (visit[v] == UNVISTED) {
            tarjanSCC(v);
        }
        if (visit[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_low[u] == dfs_num[u]) {
        cntSCC++;
        while (true) {
            int v = S.back();
            // cerr << v << " " << dfs_num[v] << " " << dfs_low[v] << endl;
            belong[v] = cntSCC;
            visit[v] = 0;
            S.pop_back();
            if (v == u) {
                break;
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;

    FOR(tc, 0, TC) {
        cin >> n >> m;
        // if (tc == 146) {
        //     cerr << n << " " << m << endl;
        // }
        arr = vvi(n+1);
        dfs_low = vi(n+1, 0);
        dfs_num = dfs_low;
        visit = vi(n+1, UNVISTED);
        belong = vi(n+1, -1);
        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            arr[u].push_back(v);
        }
        cnt = 0;
        res = 0;
        cntSCC = 0;
        
        FORE(i, 1, n) {
            if (visit[i] == UNVISTED) {
                tarjanSCC(i);
            }
        }
        // cerr << cntSCC << endl;
        brr = vi(cntSCC, 0);
        FORE(i, 1, n) {
            FOR(j, 0, (int)arr[i].size()) {
                int v = arr[i][j];
                if (belong[i] != belong[v]) {
                    // cerr << belong[i] << " " << belong[v] << endl;
                    brr[belong[v]] = 1;
                }
            }
        }
        
        FOR(i, 0, cntSCC) {
            if (brr[i] == 0) {
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}