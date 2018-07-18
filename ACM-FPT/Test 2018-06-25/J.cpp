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

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m, k;
vii brr;
int root = -1, dest = -1;
vector< vector< ii> > arr;
vi d;
int res = INF;
vi isFree;
priority_queue<ii, vector<ii>, greater<ii> > heap;

void dijkstra() {
    while (!heap.empty()) {
        ii node = heap.top();
        heap.pop();
        int u = node.second;
        int x = node.first;
        isFree[u] = false;
        cerr << u << " " << d[u] << endl;
        if (abs(brr[u].first - m) + abs(brr[u].second - n) == 0) {
            // cerr << "finish " << d[u] << endl;
            res = min(res, x);
            break;
        } else if (brr[u].first == m || brr[u].second == n) {
            res = min(res, x + 1);
            // cerr << "res = " << res << endl;
        }
        FOR(i, 0, arr[u].size()) {
            int v = arr[u][i].first;
            int c = arr[u][i].second;
            if (isFree[v] && d[v] > d[u] + c) {
                d[v] = d[u] + c;
                heap.push({d[v], v});
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> m >> n >> k;
    FOR(i, 0, k) {
        int x, y;
        cin >> x >> y;
        brr.push_back({x, y});
        if (x == 1 && y == 1) {
            root = i;
        }
        if (x == m && y == n) {
            dest = i;
        }
    }
    if (root == -1) {
        cout << -1 << endl;
        return 0;
    }
    arr = vector< vector<ii> >(k);
    FOR(i, 0, k) {
        FOR(j, i+1, k) {
            if (abs(brr[i].first - brr[j].first) + abs(brr[i].second - brr[j].second) == 1) {
                arr[i].push_back({j, 0});
                arr[j].push_back({i, 0});
                // cerr << "connect - 0: " << i << " " << j << endl;
            } else {
                if (brr[i].first == brr[j].first || brr[i].second == brr[j].second) {
                    arr[i].push_back({j, 1});
                    arr[j].push_back({i, 1});
                    // cerr << "connect - 1: " << i << " " << j << endl;
                }
            }
        }
    }
    d = vi(k+1, INF);
    isFree = vi(k+1, true);
    d[root] = 0;
    heap.push({0, root});
    dijkstra();
    if (res == INF) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}