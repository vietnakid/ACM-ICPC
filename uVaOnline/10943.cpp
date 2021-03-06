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
    	int n, k;
    	cin >> n >> k;
    	if (n == 0 && k == 0) break;

    	ll f[n+1][k+1];
    	memset(f, 0, sizeof(f));

    	FORE(i, 0, k) f[0][i] = 1;

    	FORE(i, 1, n)
    		FORE(j, 1, k) {
    			FORE(ii, 0, i) {
    				f[i][j] += f[i-ii][j-1];
    				f[i][j] %= 1000000;
    			}
    		}
    	cout << f[n][k] << endl;
    }
    return 0;
}