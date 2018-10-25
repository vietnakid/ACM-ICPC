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
    int n, p;
    double P;
    cin >> n >> P;
    p = int(round(P * 10000));

    vii arr(n);

    FOR(i, 0, n) {
        double tmp;
        cin >> arr[i].first >> tmp;
        arr[i].second = int(round(tmp * 10000));
    }
    // cerr << n << " " << p << endl;
    // cerr << arr[1].first << " " << arr[1].second << endl;

    vvi f(n, vi(100001, INF));

    f[0][arr[0].second] = arr[0].first;
    f[0][0] = 0;
    FOR(i, 1, n) {
        FOR(j, 0, 100001) {
            f[i][j] = min(f[i-1][j-arr[i].second] + arr[i].first, f[i-1][j]);
        }
    }
    // cerr << f[1][5000] << " " << p << endl;
    int res = INF;
    FOR(j, p, 100001) {
        res = min(res, f[n-1][j]);
    }
    cout << res << endl;
    return 0;
}