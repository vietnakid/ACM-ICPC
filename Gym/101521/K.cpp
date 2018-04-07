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
#define esp 0.0000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

ld dist(ld x, ld y) {
	return sqrt(x*x + y*y);
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    ll r, d;
    cin >> r >> d;

    ll resout = 0, resin = 0;
    for (ll x = 1; x <= r + d; x++) {
    	ll low = 1;
    	ll high = r+d;
    	ll onepoint = 0;
    	while (low <= high) {
    		ll mid = (low + high) >> 1;
    		// printf("dist(%lld, %lld) = ", x, mid); cout << d - fabs(dist(x, mid) - r) << endl;
    		if (d - fabs(dist(x, mid) - r) >= -esp) {
    			onepoint = mid;
    			break;
    		} else {
    			if (fabs(dist(x, (ld)mid+0.1) - r) - fabs(dist(x, (ld)mid-0.1) - r) <= esp) { //on the left side
    				low = mid+1;
    			} else {
    				high = mid-1;
    			}
    		}
    	}

    	// cout << "x = " << x << " one point = " << onepoint << endl;
    	if (onepoint != 0) { //found one point
    		ll pointleft = onepoint, pointright = onepoint;

    		// find left
    		low = 0; high = min(d+r, onepoint-1);
	    	while (low <= high) {
	    		ll mid = ((low + high) >> 1);
	    		// printf("dist(%lld, %lld) = ", x, onepoint - mid); cout << dist(x, onepoint - mid) << endl;
	    		if (d - fabs(dist(x, onepoint - mid) - r) >= -esp) {
	    			pointleft = onepoint - mid;
	    			low = mid+1;
	    		} else{
	    			high = mid - 1;
	    		}
	    	}

	    	low = 0; high = d+r;
	    	while (low <= high) {
	    		ll mid = ((low + high) >> 1);
	    		if (d - fabs(dist(x, mid + onepoint) - r) >= -esp) {
	    			pointright = mid + onepoint;
	    			low = mid+1;
	    		} else{
	    			high = mid - 1;
	    		}
	    	}

	    	resout += pointright - pointleft + 1;
	    	// cout << "found " << pointright - pointleft + 1 << " points in x = " << x << " is " << pointleft << " -> " << pointright << endl;


    	}
    	if (abs(x - r) <= d) {
    		resin++;
    	} 
   	}

   	// cout << resin << " " << resout << endl;
   	ll res0 = 0;
   	if (r <= d) res0 = 1;
   	cout << resout * 4 + resin * 4 + res0<< endl;
    return 0;
}