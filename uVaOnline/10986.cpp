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

int n, m, src, dst;
vvii arr;
priority_queue<ii, vii, greater<ii> > pq;
vi dist;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    FORE(tc, 1, TC) {
        cout << "Case #" << tc << ": ";
        cin >> n >> m >> src >> dst;
        arr = vvii(n);
        dist = vi(n, INF);
        dist[src] = 0;
        pq.push({0, src});
        FOR(i, 0, m) {
            int x, y, c;
            cin >> x >> y >> c;
            arr[x].push_back({y, c});
            arr[y].push_back({x, c});
        }
        while (!pq.empty()) {
            ii node = pq.top();
            pq.pop();
            int u = node.second;
            int d = node.first;
            if (d > dist[u]) {
                continue;
            }
            FOR(i, 0, (int)arr[u].size()) {
                int v = arr[u][i].first;
                int c = arr[u][i].second;
                if (dist[v] > d + c) {
                    dist[v] = d + c;
                    pq.push({dist[v], v});
                }
            }
        }
        if (dist[dst] == INF) {
            cout << "unreachable" << endl;
        } else {
            cout << dist[dst] << endl;
        }
    }
    return 0;
}