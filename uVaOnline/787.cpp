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
	freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	string s;
    while (getline(cin, s)) {
    	stringstream ss(s);
    	ll n = 1, p = 1, res = -INF;
    	while (true) {
    		ll x;
    		ss >> x;
    		if (x == -999999) break;
    		if (x == 0) {
    			p = 0;
    			n = 1;
    		} else if (x > 0) {
    			p = x * p;
    			n = x * n;
    		} else {
    			ll _p = p;
    			p = x * n;
    			n = x * _p;
    		}
    		res = max(res, p);
    		p = max(p, (ll)1);
    		n = min(n, (ll)1);
    	}
    	cout << res << endl;
    }
    return 0;
}