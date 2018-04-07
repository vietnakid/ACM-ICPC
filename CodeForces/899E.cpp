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
    int n;
    cin >> n;
    vi arr(n);
    FOR(i, 0, n) cin >> arr[i];
    vvi f(n);
    FOR(i, 0, n) { 
    	f[i] = vi(n, INF);
    	f[i][i] = 1;
    	if (i < n-1) {
    		if (arr[i] == arr[i+1]) f[i][i+1] = 1;
    		else f[i][i+1] = 2;
    	}
	}
    FOR(k, 2, n) {
    	FOR(i, 0, n) {
    		int j = i + k;
    		if (j >= n) break;

    		if (arr[i] == arr[j]) {
    			f[i][j] = f[i+1][j-1] + 1;
    			if (arr[i+1] == arr[j]) 
    				f[i][j] = min(f[i][j], f[i+1][j]);
    			if (arr[i] == arr[j-1]) 
    				f[i][j] = min(f[i][j], f[i][j-1]);
    		} else {
    			f[i][j] = min(f[i][j-1], f[i+1][j]) + 1;
    		}

    		cout << i << " " << j << " " << f[i][j] << endl;
    	}
    }
    
    vi g(n, INF);
    FOR(i, 0, n) {
    	g[i] = f[0][i];
    	FOR(j, 0, i) {
    		g[i] = min(g[i], g[j] + f[j+1][i]);
    	}
    }
    cout << g[n-1];
    return 0;
}