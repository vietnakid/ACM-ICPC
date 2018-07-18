#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

#define INF 1e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m;
vvi arr, brr;
vi d, d1;
int res = INF;
vi isFree;
priority_queue<ii, vector<ii>, greater<ii> > heap;

void dijkstra() {
    // while (!heap.empty()) {
    //     ii node = heap.top();
    //     heap.pop();
    //     int u = node.second;
    //     if (!isFree[u]) {
    //         continue;
    //     }
    //     // cerr << u << " " << d[u] << endl;
    //     isFree[u] = false;
    //     FORE(i, 1, n) {
    //         int v = i;
    //         ll c = arr[u][v];
    //         if (d[v] > d[u] + c) {
    //             d[v] = d[u] + c;
    //             heap.push({d[v], v});
    //         }
    //     }
    // }
    // cerr << endl << endl;

    while (true) {
        int minn = INF;
        int u = -1;
        FORE(i, 1, n) {
            if (isFree[i] && minn > d[i]) {
                minn = d[i];
                u = i;
            }    
        }
        if (u == -1) {
            break;
        }
        isFree[u] = false;
        // cerr << u << " " << d[u] << endl;
        FORE(i, 1, n) {
            if (isFree[i] && d[i] > d[u] + arr[u][i]) {
                d[i] = d[u] + arr[u][i];
            }    
        }
    }
    // cerr << endl << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> m;
    arr = vvi(n+1, vi(n+1, INF));
    brr = arr;
    FOR(i, 0, m) {
        int u, v, c;
        cin >> u >> v >> c;
        arr[u][v] = min(arr[u][v], c);
        brr[v][u] = arr[u][v];
    }

    isFree = vi(n+1, true);
    d = vi(n+1, INF);
    d[1] = 0;
    // heap.push({d[1], 1});
    dijkstra();
    res = d[n];
    
    d1 = d;
    arr = brr;
    

    isFree = vi(n+1, true);
    d = vi(n+1, INF);
    d[n] = 0;
    // heap.push({d[n], n});
    dijkstra();

    // cerr << d[n] << endl;
    
    FORE(i, 1, n) {
        FORE(j, 1, n) {
            if (i != j && arr[j][i] == INF) {
                res = min(res, d1[i] + d[j] + 1);
            }
        }
    }
    cout << res << endl;
    return 0;
}