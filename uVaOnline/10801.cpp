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

int n, k;
vvi arr;
vi t;
vi dist;
priority_queue<ii, vii, greater<ii> > pq;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    string s;
    stringstream ss;
    while (true) {
        n = -1;
        s = "";
        getline(cin, s);
        ss = stringstream(s);
        ss >> n >> k;
        if (n == -1) {
            break;
        }
        t = vi(n, 0);
        arr = vvi(100, vi(100, INF));
        getline(cin, s);
        ss = stringstream(s);
        FOR(i, 0, n) {
            ss >> t[i];
        }
        FOR(i, 0, n) {
            getline(cin, s);
            ss = stringstream(s);
            vi adj;
            while (true) {
                int x = -1;
                ss >> x;
                if (x == -1) {
                    break;
                }
                adj.push_back(x);
            }
            FOR(ii, 0, adj.size()) {
                FOR(jj, ii+1, adj.size()) {
                    int u = adj[ii], v = adj[jj];
                    arr[u][v] = min(arr[u][v], abs(v-u) * t[i]);
                    arr[v][u] = arr[u][v];
                }
            }
        }
        if (k == 0) {
            cout << 0 << endl;
            continue;
        }
        dist = vi(100, INF);
        dist[0] = -60;
        pq.push({dist[0], 0});
        while (!pq.empty()) {
            ii node = pq.top();
            pq.pop();
            int u = node.second;
            int d = node.first;
            if (d > dist[u]) {
                continue;
            }
            FOR(i, 0, 100) {
                int v = i;
                if (dist[v] > dist[u] + arr[u][v] + 60) {
                    dist[v] = dist[u] + arr[u][v] + 60;
                    pq.push({dist[v], v});
                    
                }
            }
        }
        if (dist[k] == INF) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << dist[k] << endl;
        }
    }
    return 0;
}