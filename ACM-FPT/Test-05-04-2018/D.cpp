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
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    cin >> n;
    FOR (i, 0, n) {
    	ll a, b; cin >> a;
    	vl res;
        b = a;
        ll x2 = 1;
        while (b % 2 == 0) {
            x2 *= 2;
            b /= 2;
        }
        ll x3 = 1;
        while (b % 3 == 0) {
            x3 *= 3;
            b /= 3;
        }
        if (x2*x3 == a) {
            a = 0;
            res.push_back(x2*x3);
        }
    	while (a > 0) {
    		b = a;
    		ll x = 1;
    		while (b % 2 == 0) {
    			x *= 2;
    			b /= 2;
    		}
    		ll tmp = log(b) / log(3);
    		a = a - x*pow(3, tmp);
    		res.push_back(x*pow(3, tmp));
    	}
    	cout << res.size() << endl;
    	reverse(res.begin(), res.end());
    	FOR(i, 0, res.size()) {
    		cout << res[i] << " ";
    	}
    	cout << endl;
    }
    return 0;
}