#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
	freopen("input.in", "r", stdin);
	freopen("output", "w", stdout);
    int n;
    cin >> n;
    REP(ii, 0, n) {
    	ll a, b, c;
    	cin >> a >> b >> c;
    	bool sol = true;
    	ll high = min(sqrt(c), pow(b, 1./3.));
    	for(ll x = -high; x <= high && sol; x++) {
    		if (x != 0 && b % x == 0) {
    			ll A = a - x;
    			ll B = b / x;
    			ll C = c - (x*x);
    			ll delta = A*A - 4*B;

    			ll y = 0, z = 0;

    			if (delta >= 0) {
    				ll sqrtdelta = sqrt(delta);
    				if (sqrtdelta * sqrtdelta == delta) {
    					if ((A - sqrtdelta) % 2 == 0) {
    						y = (A - sqrtdelta) / 2;
    						if (B % y == 0) {
    							z = B / y;
	    						if (x != y && y != z && x != z && y*y + z*z == C) {
	    							vl arr;
				    				arr.push_back(x); arr.push_back(y); arr.push_back(z);
				    				sort(arr.begin(), arr.end());
									cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
									sol = false;
	    						}
    					}
    					}
    				}
    			}

    			
    		}
    		
    	}
    	if (sol) {
    		cout << "No solution." << endl;
    	}
    }
    return 0;
}
