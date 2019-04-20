#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
vvi arr;
ll value[100005], modu[100005];
vii res;

void DFS(int u, int father, ll G) {
    if (arr[u].size() == 1 && arr[u][0] == father) { // leaf
        G = G % modu[u];
        ll _G = GCD(G, modu[u]);
        ll remain = ((modu[u] - 1) / _G) * _G;
        res.push_back({u, remain});
        // cerr << u << " " << G << " " << remain << "\n";
    } else {
        for (auto v : arr[u]) {
            if (v != father) {
                DFS(v, u, GCD(G, value[v]));
            }
        }
    }
}

void vietnakid() {
	int TC; cin >> TC;
    while (TC--) {
        cin >> n;
        arr.clear(); arr.resize(n+1);
        res.clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            cin >> value[i];   
        }
        for (int i = 1; i <= n; i++) {
            cin >> modu[i];
        }
        DFS(1, 0, value[1]);
        sort(res.begin(), res.end());
        for (auto r : res) {
            cout << r.second << " ";
        }
        cout << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}