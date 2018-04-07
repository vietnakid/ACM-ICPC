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
    int n = 0;
    cin >> n;
    if (n == 0) break;
    vvl arr(n), f(n);
    FOR(i, 0, n) {
    	f[i] = vl(n, 0);
    	arr[i] = vl(n);
    }
    FOR(i, 0, n)
    	FOR(j, 0, n) cin >> arr[i][j];
    ll res = arr[0][0];
    f[0][0] = arr[0][0];
    FOR(i, 0, n) {
    	FOR(j, 0, n) {
    		if (i != 0 && j != 0)
    			f[i][j] = arr[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
    		else 
    			if (i == 0 && j != 0)
    				f[i][j] = f[i][j-1] + arr[i][j];
    			if (i != 0 && j == 0) 
    				f[i][j] = f[i-1][j] + arr[i][j];
    		// cout << i << " " << j << " " << f[i][j] << endl;
    	}
    }


    FOR(i, 0, n)
    	FOR(j, 0, n)
    		FORE(ii, 0, i)
    			FORE(jj, 0, j) {

    				ll sum = -INF;
    				if (ii != 0 && jj != 0) {
    					sum = f[i][j] + f[ii-1][jj-1] - f[i][jj-1] - f[ii-1][j];
    				} else
					if (ii == 0 && jj != 0) {
						sum = f[i][j] - f[i][jj-1];
					} else   				
					if (ii != 0 && jj == 0) {
						sum = f[i][j] - f[ii-1][j];
					} else 
						sum = f[i][j];   
					res = max(res, sum);		
					// cout << ii << " " << jj << " " << i << " " << j << " " << sum << endl;		
    			}
    cout << res << endl;
}
    return 0;
}