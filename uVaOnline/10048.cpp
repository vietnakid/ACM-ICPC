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

priority_queue< pair<ld, ii>, vector< pair<ld, ii> >, greater<pair<ld, ii> > > heap;
int n, m, q;
vi root;
int cnt;
vector< vector< ii> > arr;

int findRoot(int u) {
    while (root[u] != -1) {
        u = root[u];
    }
    return u;
}

void connectRoot(int u, int v) {
    root[findRoot(v)] = findRoot(u);
}

int findPath(int u, int dest, int father) {
    int res = 0;
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i].first;
        if (v == father) {
            continue;
        }
        if (v == dest) {
            return arr[u][i].second;
        } else {
            int x = findPath(v, dest, u);
            if (x != 0) {
                res = max(x, arr[u][i].second);
            }
        }
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int tc = 0;
    while (true) {
        cin >> n >> m >> q;
        if (n == 0 && m == 0 && q == 0) {
            break;
        }
        tc++;
        if (tc != 1) {
            cout << endl;
        }
        cout << "Case #" << tc << '\n';
        cnt = 0;
        root = vi(n+1, -1);
        FOR(i, 0, m) {
            int u, v, x;
            cin >> u >> v >> x;
            heap.push({x, {u, v}});
        }
        arr = vector< vector< ii> >(n+1);
        while (!heap.empty()) {
            pair<ld, ii> node = heap.top();
            heap.pop();
            int u = node.second.first;
            int v = node.second.second;
            int x = node.first;
            if (findRoot(u) != findRoot(v)) {
                arr[u].push_back({v, x});
                arr[v].push_back({u, x});
                connectRoot(u, v);
            } 
        }
        FOR(i, 0, q) {
            int u, v;
            cin >> u >> v;
            int res = findPath(u, v, -1);
            if (res == 0) {
                cout << "no path" << endl;
            } else {
                cout << res << endl;
            }
        }
    }
    return 0;
}
