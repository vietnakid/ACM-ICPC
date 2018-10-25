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
#define INFLL 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m, s, t, p;
vvii arr, brr;
priority_queue<ii, vii, greater<ii> > pq;
vi da, db;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> m >> s >> t >> p;
        arr = vvii(n+1);
        brr = vvii(n+1);
        FOR(i, 0, m) {
            int u, v, c;
            cin >> u >> v >> c;
            arr[u].push_back({v, c});
            brr[v].push_back({u, c});
        }
        da = vi(n+1, INF);
        da[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            ii node = pq.top();
            pq.pop();
            int u = node.second;
            int d = node.first;
            if (d > da[u]) {
                continue;
            }
            FOR(i, 0, arr[u].size()) {
                int v = arr[u][i].first;
                int c = arr[u][i].second;
                if (da[v] > d + c) {
                    da[v] = d + c;
                    pq.push({da[v], v});
                }
            }
        }

        db = vi(n+1, INF);
        db[t] = 0;
        pq.push({0, t});
        while (!pq.empty()) {
            ii node = pq.top();
            pq.pop();
            int u = node.second;
            int d = node.first;
            if (d > db[u]) {
                continue;
            }
            FOR(i, 0, brr[u].size()) {
                int v = brr[u][i].first;
                int c = brr[u][i].second;
                if (db[v] > d + c) {
                    db[v] = d + c;
                    pq.push({db[v], v});
                }
            }
        }

        int res = -1;
        // cerr << da[2] << endl;
        FOR(u, 0, n) {
            FOR(i, 0, arr[u].size()) {
                int v = arr[u][i].first;
                int c = arr[u][i].second;
                if (da[u] + db[v] + c <= p) {
                    res = max(res, c);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}