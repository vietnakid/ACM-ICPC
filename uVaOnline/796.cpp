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
vvi arr;
int n;
vi dfsNum, dfsLow, parent;
vii bridges;
int cnt;

void findBridge(int u) {
    dfsNum[u] = dfsLow[u] = cnt++;
    for (auto v : arr[u]) {
        if (dfsNum[v] == 0) {
            parent[v] = u;
            findBridge(v);
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
            if (dfsLow[v] > dfsNum[u]) {
                if (u < v){
                    bridges.push_back({u, v});
                } else {
                    bridges.push_back({v, u});
                }
            }
        }
        if (parent[u] != v) {
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
        n = -1;
        cin >> n;
        if (n == -1) {
            break;
        }
        arr = vvi (n);
        FOR(i, 0, n) {
            int u, m;
            cin >> u;
            char x;
            cin >> x;
            cin >> m;
            cin >> x;
            // cout << u << " " << m << endl;
            FOR(j, 0, m) {
                int v;
                cin >> v;
                arr[u].push_back(v);
                arr[v].push_back(u);
            }
        }
        bridges = vii(0);
        dfsNum = vi(n, 0);
        dfsLow = vi(n, 0);
        parent = vi(n, -1);
        cnt = 1;
        FOR(i, 0, n) {
            if (dfsNum[i] == 0) {
                findBridge(i);
            }
        }
        cout << bridges.size() << " critical links" << endl;
        sort(bridges.begin(), bridges.end());
        for (auto it : bridges) {
            cout << it.first << " - " << it.second << endl;
        }
        cout << endl;
    }
    return 0;
}