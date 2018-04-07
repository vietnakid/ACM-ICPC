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

ll f[51][51][51];

ll cal(ll n, ll k, ll m) {
	// cout << n << " " << k << " " << m << endl;
	if (n < k || k <= 0 || n <= 0 || m <= 0) return 0;
	if (n == k*m || (k == 1 && n <= m) ) f[n][k][m] = 1;
	if (f[n][k][m] != -1) return f[n][k][m];
	ll res = 0;
	FORE(i, 1, m) res += cal(n-i, k-1, m);
	f[n][k][m] = res;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	memset(f, -1, sizeof(f));
    while (true) {
    	ll n, k, m = -1;
    	cin >> n >> k >> m;
    	if (m == -1) break;
    	cout << cal(n, k, m) << endl;
    }
    return 0;
}