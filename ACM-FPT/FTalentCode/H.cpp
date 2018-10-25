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
    int n, k;
    cin >> n >> k;
    vi a(k+1);
    vector<double> c(k+1);
    FORE(i, 1, k) {
        cin >> a[i] >> c[i];
    }
    vector<vector<double> > f(k+1, vector<double>(n+1, INF));
    FORE(i, 1, k) {
        f[i][0] = 0;
        FORE(j, 1, n) {
            int r = max(j - a[i], 0);
            f[i][j] = min(min(f[i-1][r], f[i][r]) + c[i], f[i-1][j]);
            // cout << i << " " << j << " " << f[i][j] << endl;
        }
    }
    vi res(k+1, 0);
    int K = k;
    // cerr << f[k][n] << endl;
    while (n > 0) {
        int r = max(n - a[k], 0);
        // cerr << k << " " << n << " " << r << " " << f[k][n] - f[k][r] - c[k] << endl;
        if (abs(f[k][n] - f[k-1][n]) < esp) {
            k--;
        } else if (abs(f[k][n] - f[k][r] - c[k]) < esp) {
            res[k]++;
            n = r;
        } else if (abs(f[k][n] - f[k-1][r] - c[k]) < esp) {
            res[k]++;
            n = r;
            k--;
        }
    }
    FORE(i, 1, K) {
        cout << res[i] << " ";
    }
    return 0;
}