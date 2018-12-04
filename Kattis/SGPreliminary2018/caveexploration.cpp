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
vvi arr;
vi father;
vi visited;
vi minValue;
vi value;
int cur = 0, res = 0;

void findBridge(int u) {
    minValue[u] = value[u] = cur++;
    visited[u] = true;
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        if (v != father[u]) {
            if (!visited[v]) {
                father[v] = u;
                findBridge(v);
                minValue[u] = min(minValue[u], minValue[v]);
            } else {
                minValue[u] = min(minValue[u], value[v]);
            }
            if (value[u] < minValue[v]) {
                // cerr << "Bridge " << u << " " << v << endl;
                arr[u].erase(find(arr[u].begin(), arr[u].end(), v));
                arr[v].erase(find(arr[v].begin(), arr[v].end(), u));
                i--;
            }
        }
    }
    // cerr << u <<  " value " << value[u] << " minValue " << minValue[u] << endl;
}

void DFS(int u) {
    visited[u] = true;
    res++;
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        if (!visited[v]) {
            DFS(v);
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
    arr = vvi(n);
    father = vi(n, -1);
    visited = vi(n, false);
    minValue = vi(n, 0);
    value = vi(n, 0);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    findBridge(0);
    visited = vi(n, false);
    DFS(0);
    cout << res << endl;
    return 0;
}