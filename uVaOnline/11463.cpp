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
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        int n, m;
        cin >> n >> m;
        vvi arr(n, vi(n, INF));
        FOR(i, 0, n) {
            arr[i][i] = 0;
        }
        FOR(i, 0, m) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
            arr[y][x] = 1;
        }
        FOR(k, 0, n) {
            FOR(i, 0, n) {
                FOR(j, 0, n) {
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }
        int src, dst;
        cin >> src >> dst;
        int res = 0;
        FOR(k, 0, n) {
            res = max(res, arr[src][k] + arr[k][dst]);
        }
        cout << "Case " << tc << ": " << res << endl;
    }
    return 0;
}