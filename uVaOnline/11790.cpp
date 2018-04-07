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
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
    	printf("Case %d. ", tc);
    	int n;
    	cin >> n;
    	vi height(n), width(n);
    	FOR(i, 0, n) cin >> height[i];
    	FOR(i, 0, n) cin >> width[i];

    	height.push_back(INF);
    	width.push_back(0);
    	vi g(n+1, 0), l(n+1, 0);

	    // cal greater
	    FORE(i, 0, n) {
	    	FOR(j, 0, i) {
	    		if (height[j] < height[i]) g[i] = max(g[i], g[j]);
	    	}
	    	g[i] += width[i];
	    }

	    // cal less
	    height[n] = -INF;
	    FORE(i, 0, n) {
	    	FOR(j, 0, i) {
	    		if (height[j] > height[i]) l[i] = max(l[i], l[j]);
	    	}
	    	l[i] += width[i];
	    }
	    if (l[n] > g[n]) {
	    	printf("Decreasing (%d). Increasing (%d).\n", l[n], g[n]);
	    } else
	    	printf("Increasing (%d). Decreasing (%d).\n", g[n], l[n]);
	}
    return 0;
}