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

priority_queue< ll, vector<ll>, greater<ll> > heap;

vi isFree;

vi res;
vvi arr;

void DFS(int u) {
    isFree[u] = false;
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        if (isFree[v]) {
            DFS(v);
        }
    }
    res.push_back(u);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        res.clear();
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        arr = vvi(n + 1);
        FOR(i, 0, m) {
            int x, y;
            cin >> x >> y;
            arr[x].push_back(y);
        }
        isFree = vi(n + 1, true);
        FORE(i, 1, n) {
            if (isFree[i]) {
                DFS(i);
            }
        }
        FORD(i, n-1, 0) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}