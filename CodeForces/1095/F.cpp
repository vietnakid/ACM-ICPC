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

int n, m;
vii arr;
vl a(1);
vector< pair<ll, ii> > edge;
int root[200005];

int getRoot(int u) {
    if (root[u] == 0) {
        return u;
    }
    return root[u] = getRoot(root[u]);
}

void unionRoot(int u, int v) {
    root[getRoot(u)] = getRoot(v);
}

void MST() {
    ll res = 0;
    for (int i = 0; i < edge.size(); i++) {
        ll w = edge[i].first;
        int u = edge[i].second.first;
        int v = edge[i].second.second;
        if (getRoot(u) != getRoot(v)) {
            res += w;
            unionRoot(u, v);
            // cerr << u << " " << v << " " << w << "\n";
        }
    }
    cout << res << "\n";
}

void vietnakid() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        arr.push_back({x, i+1});
        a.push_back(x);
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++) {
        if (i != arr[0].second) {
            edge.push_back({a[arr[0].second] + a[i], {arr[0].second, i}});
        }
    }
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }
    sort(edge.begin(), edge.end());
    MST();
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