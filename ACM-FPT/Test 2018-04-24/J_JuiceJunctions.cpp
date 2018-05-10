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

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int n, m;
vvi arr, brr;
vi d;
int res = 0;

void DFS(int u) {
    if (u == 0) return;
    d[u]++;
    cout << u << endl;
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        arr[u][i] = 0;
        FOR(j, 0, arr[v].size()) {
            if (arr[v][j] == u) {
                arr[v][j] = 0;
            }
        }
        cout << " - > " << v << endl;
        DFS(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> m;
    brr = vvi(n+1);
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        brr[x].push_back(y);
        brr[y].push_back(x);
    }
    FORE(i, 1, 1) {
        arr = brr;
        d = vi(n+1, 0);
        DFS(i);
        FORE(j, 1, n+1) {
            res += d[j];
        }
        res -= d[i];
    }
    cout << res/2 << endl;
    return 0;
}
