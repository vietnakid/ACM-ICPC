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
    int TC;
    cin >> TC;
    FORE(tc, 1, TC) {
    	printf("Case #%d: ", tc);
    	int n, m, k;
    	cin >> m >> n >> k;
    	vvi arr(m);
    	FOR(i, 0, m)
    		arr[i] = vi(n);
    	FOR(i, 0, m)
    		FOR(j, 0, n) cin >> arr[i][j];
    	int res = 0, resa = 0;

    	vvi sum(m);
    	FOR(i, 0, m)
    		sum[i] = vi(n);

    	FOR(i, 0, m) {
    		FOR(j, 0, n)
    			if (j == 0) sum[i][j] = arr[i][j];
    			else sum[i][j] = sum[i][j-1] + arr[i][j];
    	}

    	FOR(i, 0, n)
    		FOR(j, i, n) {
    			vi f(m);
    			FOR(ii, 0, m) {
					if (i == 0) 
						f[ii] = sum[ii][j];
					else
						f[ii] = sum[ii][j] - sum[ii][i-1];
    			}

    			int ii = 0, sum = 0;
    			FOR (jj, 0, m) {
    				sum += f[jj];
    				// cout << f[jj] << endl;
    				while (sum > k) {
    					sum -= f[ii];
    					ii++;
    				}
    				// cout << i << " " << j << " " << ii << " " << jj << " " << sum << endl;
    				if (res <= k) {
    					if ((j-i+1)*(jj-ii+1) > resa || ((j-i+1)*(jj-ii+1) == resa && res > sum)) {
	    					resa = (j-i+1)*(jj-ii+1);
	    					res = sum;
	    				}
    				}
    			}
    		}
    	printf("%d %d\n", resa, res);
    }
    return 0;
}