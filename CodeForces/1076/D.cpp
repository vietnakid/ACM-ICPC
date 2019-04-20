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

int n, m, k;
vii arr[300005];
vi order[300005];
vl d(300005, INFLL);
int trace[300005];
int cnt = 0;
priority_queue<ii, vii, greater<ii> > heap;
vi res;

void dijkstra() {
    while (!heap.empty()) {
        ii cur = heap.top(); heap.pop();
        int u = cur.second;
        ll w = cur.first;
        if (w != d[u]) continue;
        cnt++;
        res.push_back(trace[u]);
        if (cnt == k+1) return;
        for (int i = 0; i < arr[u].size(); i++) {
            ii edge = arr[u][i];
            int v = edge.first;
            ll c = edge.second;
            if (w + c < d[v]) {
                d[v] = w+c;
                trace[v] = order[u][i];
                heap.push({d[v], v});
            }
        }
    }
}

void vietnakid() {
	cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        arr[u].push_back({v, c});
        order[u].push_back(i+1);
        arr[v].push_back({u, c});
        order[v].push_back(i+1);
    }
    d[1] = 0;
    heap.push({0, 1});
    trace[1] = 0;
    dijkstra();
    cout << cnt - 1 << "\n";
    for (int i = 1; i <= cnt-1; i++) {
        cout << res[i] << " ";
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