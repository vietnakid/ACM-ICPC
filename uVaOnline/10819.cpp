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
typedef set<int> si;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    while (true) {
    	int m, n = -INF;
    	cin >> m >> n;
    	if (n == -INF) break;
    	vi arr(n), brr(n);
    	FOR(i, 0, n) cin >> arr[i] >> brr[i];
    	int f[n][m+201];
    	memset(f, -1, sizeof(f));
    	f[0][0] = 0;
    	int res = 0;
    	FOR(i, 0, n) {
    		FORE(j, 0, m+200) {
    			if (i == 0) {
    				if (j == arr[i]) f[i][j] = brr[i];
    			} else {
    				f[i][j] = f[i-1][j];
    				if (j - arr[i] >= 0 && f[i-1][j - arr[i]] != -1)
    					f[i][j] = max(f[i][j], f[i-1][j - arr[i]] + brr[i]);
    			}
    			if (j <= m || j > 2000)
    				res = max(res, f[i][j]);
    		}
    	}
    	cout << res << endl;
    }
    return 0;
}