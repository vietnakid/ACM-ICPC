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
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int n, m;
    cin >> n >> m;
    vl X(n, 0), Y(m, 0), x(n, 0), y(m, 0);
    ll res = 0;
    REP(i, 0, n) 
    	REP(j, 0, m) {
    		int k;
    		cin >> k;
    		res += k;
    		X[i] += k;
    		Y[j] += k;
    	}
    res *= 2;

    REP(i, 0, n) 
    	REP(j, 0, n)
    		if (i != j) {
    			x[i] += abs(i-j)*X[j]*2;
    		}
    
	REP(i, 0, m) 
    	REP(j, 0, m)
    		if (i != j) {
    			y[i] += abs(i-j)*Y[j]*2;
    		}
    
    // REP(i, 0, n) cout << x[i] << " ";
    // cout << endl;
    // REP(i, 0, m) cout << y[i] << " ";
    // cout << endl;

    ll minn = INFLL, resx = 0, resy = 0;
    REP(i, 0, n) 
    	if (x[i] < minn) {
    		minn = x[i];
    		resx = i;
    	}
    minn = INFLL;
    REP(i, 0, m) 
    	if (y[i] < minn) {
    		minn = y[i];
    		resy = i;
    	}

    cout << resx+1 << " " << resy+1 << " " << res+x[resx]+y[resy] << endl;
    return 0;
}