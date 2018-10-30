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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m;
vvii arr;
vi isFreeEdge;
vi child;
vi dfsNum;
vi dfsLow;
vi countNode;
int cnt;
vii edge;

vi qq;
vi myChild;

void findBridge(int u) {
    // cerr << "u = " << u << endl;
    qq.push_back(u);
    dfsNum[u] = dfsLow[u] = cnt++;
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i].first;
        int ed = arr[u][i].second;
        if (dfsNum[v] == 0) {
            // cerr << v << endl;
            isFreeEdge[ed] = false;
            findBridge(v);
            myChild[u] += myChild[v];
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
            if (dfsLow[v] > dfsNum[u]) {
                int countChild = myChild[v];
                child[ed] = countChild;
                cerr << "bridge " << u << " " << v << " " << ed << " " << countChild << endl;
            }
        }
        if (isFreeEdge[ed]) {
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> m;
    arr = vvii(n+1);
    isFreeEdge = vi(m+1, true);
    child = vi(m+1, 0);
    edge = vii(m+1);
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        arr[x].push_back({y, i});
        arr[y].push_back({x, i});
        edge[i] = {x, y};
    }
    dfsNum = vi(n+1, 0);
    dfsLow = vi(n+1, 0);
    countNode = vi(n+1, 0);
    myChild = vi(n+1, 1);
    cnt = 1;
    FORE(i, 1, n) {
        if (dfsNum[i] == 0) {
            qq.clear();
            int beg = cnt;
            findBridge(i);
            int allNode = cnt - beg;
            for(auto u : qq) {
                countNode[u] = allNode;
            }
        }
    }
    int q;
    cin >> q;
    FOR(i, 0, q) {
        int x;
        cin >> x;
        x--;
        ll res = (ll)child[x] * (ll)(countNode[edge[x].first] - child[x]);
        cout << res << endl;
        // cout << res << " " << child[x] << " " << countNode[edge[x].first] << " " << edge[x].first << " " << edge[x].second << endl;
    }
    return 0;
}