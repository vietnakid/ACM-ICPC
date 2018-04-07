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

#define INF 1e9 // 2e9
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
    int TC; cin >> TC;
    while (TC--) {
    	int n; cin >> n;
    	n /= 100;
    	vvi arr(10), f(10);
    	FOR(i, 0, 10) { 
    		arr[i] = vi(n+1, 0);
    		f[i] = vi(n+2, INF);
    	}

    	for(int i = 9; i >= 0; i--) {
    		FORE(j, 1, n) 
    			cin >> arr[i][j];
    	}

    	f[0][1] = 0;

    	FORE(j, 2, n+1) {
    		FOR(i, 0, 10) {
    			if (i == 0) {
    				f[i][j] = min(f[i][j-1] + 30 - arr[i][j-1], f[i+1][j-1] + 20 - arr[i+1][j-1]);
    			} else if (i == 9) {
    				f[i][j] = min(f[i][j-1] + 30 - arr[i][j-1], f[i-1][j-1] + 60 - arr[i-1][j-1]);
    			} else {
    				f[i][j] = min(f[i][j-1] + 30 - arr[i][j-1], min(f[i-1][j-1] + 60 - arr[i-1][j-1], f[i+1][j-1] + 20 - arr[i+1][j-1]));
    			}
    		}
    	}
    	cout << f[0][n+1] << endl << endl;
    }

    return 0;
}