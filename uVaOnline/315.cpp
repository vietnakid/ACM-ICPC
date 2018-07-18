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

int n;
vvi arr;
vi parent, dfsnum, dfslow, articulationPoint;
int cnt, rootdfs, childRoot;

int tc = 0;

void DFS(int u) {
    dfsnum[u] = dfslow[u] = ++cnt;
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        if (dfsnum[v] == -1) { //unvisit
            parent[v] = u;
            DFS(v);
            if (u == rootdfs) {
                childRoot++;
            }
            if (dfslow[v] >= dfsnum[u]) {
                articulationPoint[u] = true;
                // cout << u << endl;
            }
            dfslow[u] = min(dfslow[u], dfslow[v]);
        } else if (v != parent[u]) {
            dfslow[u] = min(dfslow[u], dfsnum[v]);
        }
    }

}


void solve() {
    tc++;
    if (tc == 123) {
        cerr << n;
        FORE(u, 1, n) {
            FOR(i, 0, arr[u].size()) {
                int v = arr[u][i];
                if (v > u)
                    cerr << u << " " << arr[u][i] << endl;
            }
        }
    }
    parent = vi(n+1, 0);
    dfsnum = vi(n+1, -1);
    dfslow = vi(n+1, 0);
    articulationPoint = vi(n+1, false);
    cnt = 0;
    rootdfs = 1;
    childRoot = 0;
    DFS(rootdfs);
    int res = 0;
    articulationPoint[rootdfs] = childRoot > 1;
    FORE(i, 1, n) {
        bool x = articulationPoint[i];
        if (x) res++;
    }
    cout << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    string s;
    stringstream ss;
    while (true) {
        getline(cin, s);
        ss = stringstream(s);
        ss >> n;
        if (n == 0) {
            break;
        }
        arr = vvi(n+1);
        while (true) {
            int u;
            getline(cin, s);
            ss = stringstream(s);
            ss >> u;
            if (u == 0) {
                break;
            }
            int v;
            while (!ss.eof()) {
                ss >> v;
                arr[u].push_back(v);
                arr[v].push_back(u);
            }
        }
        solve();
    }
    return 0;
}