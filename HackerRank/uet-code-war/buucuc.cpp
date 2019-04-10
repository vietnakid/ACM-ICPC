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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll n, e;
vvi arr(1005);
ll q[1005];
ll dp[1005];

vvi d(5005, vi(5005, INF));
priority_queue <ii, vector<ii>, greater<ii> > pq;

void dijkstra(int node) {
    while (pq.size()){
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du!=d[node][u]) continue;

        for (auto v : arr[u])
        {
            if (d[node][v] > du+1) {
                d[node][v]=du+1;
                pq.push({d[node][v], v});
            }
        }
    }
}


void init() {
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
        pq.push({0, i});
        dijkstra(i);
    }
}

ll calDP(int u) {
    ll & res = dp[u];
    if (res != -1) return res;
    res = q[u];
    for (int v = 1; v <= n; v++) {
        if (q[v] > q[u])
            res = max(res, q[u] - d[u][v]*e + calDP(v));
    }
    return res;
}

void sovle() {
    memset(dp, -1, sizeof(dp));
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, calDP(i));
        // cerr << i << " " << calDP(i) << "\n";
    }
    cout << res << "\n";
}


void vietnakid() {
    cin >> n >> e;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
        int d; cin >> d;
        for (int j = 0; j < d; j++) {
            int v; cin >> v;
            arr[i].push_back(v);
        }
    }

    init();
    sovle();
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