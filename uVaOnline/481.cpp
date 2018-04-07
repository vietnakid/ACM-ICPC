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
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	vl arr;
    while (true) {
    	ll x = -INFLL;
    	cin >> x;
    	if (x == -INFLL)  break;
    	arr.push_back(x);
    }
    int n = arr.size();
    vl f(n+1, INFLL), res;
    int resn = 0;
    f[0] = -INFLL;
    FOR(i, 0, n) {
    	vl::iterator it = lower_bound(f.begin(), f.end(), arr[i]);
    	*it = arr[i];
    	int l = distance(f.begin(), it);
    	// cout << l << endl;
    	if (l >= resn) {
    		resn = l;
    		res = f;
    	}
    }
    cout << resn << endl << '-' << endl;
    FORE(i, 1, resn) {
    	cout << res[i] << endl;
    }
    return 0;
}