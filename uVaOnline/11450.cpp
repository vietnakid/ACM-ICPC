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

#define REP(i, a, b) \
    for (int i = (a); i < (b); i++)
#define REPE(i, a, b) \
    for (int i = (a); i <= (b); i++)

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
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
    int TC; cin >> TC;
    while (TC--) {
    	int m, c;
    	cin >> m >> c;
    	vvi arr(c);
    	REP(i, 0, c) {
    		int k;
    		cin >> k;
    		arr[i] = vi(k);
    		REP(j, 0, k) {
    			int x;
    			cin >> x;
    			arr[i][j] = x;
    		}
    	}

    	vvi f(c+1);
    	REP(i, 0, c+1)
    		f[i] = vi(m+1, 0);
    	f[0][0] = 1;
    	REP(i, 1, c+1) {
    		REPE(j, 0, m) {
    			REP(ii, 0, arr[i-1].size() ) {
    				if (j-arr[i-1][ii] >= 0 && f[i-1][j-arr[i-1][ii]])
    					f[i][j] = 1;	
    			}
    		}
    	}
    	int res = 0;
    	REPE(j, 0, m)
    		if (f[c][j])
    			res = j;
    	if (res > 0)
    		cout << res << endl;
    	else 
    		cout <<  "no solution" << endl;
    }
    return 0;
}