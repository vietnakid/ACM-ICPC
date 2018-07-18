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
vi dfsNum, dfsLow, parent;
vi articulationPoint;
int cnt;
int rootTree = 0;
int rootChild = 0;
vii res;

void findArticualtionPoint(int u) {
    dfsNum[u] = dfsLow[u] = cnt++;
    for (auto v : arr[u]) {
        if (dfsNum[v] == 0) {
            parent[v] = u;
            findArticualtionPoint(v);
            if (u != rootTree) {
                if (dfsLow[v] >= dfsNum[u]) {
                    articulationPoint[u]++;
                }
            } else {
                rootChild++;
            }
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        if (v != parent[u]) {
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
        }
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
        if (n == 0 && m == 0) break;
        arr = vvi(n);
        while (true) {
            int u, v;
            cin >> u >> v;
            if (u == -1 && v == -1) break;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        
        dfsNum = vi(n, 0);
        dfsLow = vi(n, 0);
        parent = vi(n, -1);
        articulationPoint = vi(n, 1);
        cnt = 1;
        rootChild = 0;
        findArticualtionPoint(0);
        articulationPoint[rootTree]= rootChild;
        res = vii(0);
        FOR(i, 0, articulationPoint.size()) {
            int x = articulationPoint[i];
            res.push_back({x, -i});
        }
        sort(res.rbegin(), res.rend());
        FOR(i, 0, m) {
            cout << -(res[i].second) << " " << res[i].first << endl;
        }
        cout << endl;
    }
    return 0;
}