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
    	ll n = -INFLL, l, u;
    	cin >> n >> u >> l;
    	if (n == -INFLL) break;

    	ll res = 0;
    	for (ll i = 31; i >= 0; i--) {
    		if (res + ((ll)1 << i) > l) {
    			// cout << "must be 0" << endl;
    		}  else if (res + ((ll)1 << i) <= u) {
    			// cout << "must be 1" << endl;
    			res += ((ll)1 << i);
    		} else {
    			if ((n & ((ll)1 << i)) == 0) {
    				res += ((ll)1 << i);
    			}
    		}
    		// cout << ((ll)1 << i) << " " << (n & ((ll)1 << i)) << " " << res << endl;
    	}
    	cout << res << endl;
    }
    return 0;
}