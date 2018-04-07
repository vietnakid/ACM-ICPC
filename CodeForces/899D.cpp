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
    ll n;
    cin >> n;
    if (n < 5) {
    	cout << n*(n-1)/2;
    	return 0;
    }

    ll a = 4, b = 5, res = 1;
    while (true) {
    	a = a * 10 + 9;
    	b *= 10;
    	if (b <= n) res++;
    	else break;
    }
    ll x = 0, base = 1;
    FOR(i, 0, res) {
    	x = x * 10 + 9;
    	base *= 10;	
    }
    
    res = 0;
    FOR(i, 0, 9) {

    	if (x / 2 + 1 <= n) {
    		if (x <= n)
    			res += x/2;
    		else 
    			res += n - (x/2);
    	}
    	// cout << x << " " << res << endl;
    	x += base;
    }
    cout << res << endl;
    return 0;
}