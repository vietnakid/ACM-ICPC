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
int n, r;
vii arr;
vi root;

ld distance(int i, int j) {
    ld x = (arr[i].first - arr[j].first);
    ld y = (arr[i].second - arr[j].second);
    return x*x + y*y;
}

int findRoot(int u) {
    while (root[u] != -1) {
        u = root[u];
    }
    return u;
}

void connectRoot(int u, int v) {
    root[findRoot(v)] = findRoot(u);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    FORE(tc, 1, TC) {
        arr.clear();
        heap = priority_queue< pair<ld, ii>, vector< pair<ld, ii> >, greater<pair<ld, ii> > > ();
        cin >> n >> r;
        FOR(i, 0, n) {
            int x, y;
            cin >> x >> y;
            arr.push_back({x, y});
        }
        FOR(i, 0, n) {
            FOR(j, i+1, n) {
                heap.push({distance(i, j), {i, j}});
            }
        }
        root = vi(n, -1);
        ld resRoad = 0, resRail = 0;
        int numSCC = 1;
        while (!heap.empty()) {
            pair<ld, ii> node = heap.top();
            heap.pop();
            int u = node.second.first;
            int v = node.second.second;
            ld x = node.first;
            if (findRoot(u) != findRoot(v)) {
                // cerr << u << " " << v << " " << sqrt(x) << endl;
                connectRoot(u, v);
                if (sqrt(x) >= r) {
                    resRail += sqrt(x);
                    numSCC++;
                } else {
                    resRoad += sqrt(x);
                }
            }
        }
        // cerr << resRoad << " " << resRail << endl;
        printf("Case #%d: %d %d %d\n", tc, numSCC, (int)round(resRoad), (int)round(resRail));
    }
    return 0;
}