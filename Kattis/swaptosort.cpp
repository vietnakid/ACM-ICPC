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

int n, k;
vi SC;
vvi arr;
vi visited;
int sc = 0;

void DFS(int u) {
    SC[u] = sc;
    visited[u] = true;
    // cerr << u << " " << sc << endl;
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
    cin >> n >> k;
    SC = vi(n, 0);
    arr = vvi(n);
    visited = vi(n, false);
    FOR(i, 0, k) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }    
    FOR(i, 0, n) {
        // cerr << i << " " << visited[i] << endl;
        if (!visited[i]) {
            
            sc++;
            DFS(i);
        }
    }
    bool res = true;
    FOR(i, 0, n/2) {
        if (SC[i] != SC[n-i-1]) {
            res = false;
            break;
        }
    }
    if (res) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}