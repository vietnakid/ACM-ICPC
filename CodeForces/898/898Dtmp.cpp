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
    for (ll i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (ll i = (a); i <= (b); i++)

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
    ll n, m, k;
    cin >> n >> m >> k;
    int nMAX = 0;
    set<int> arr;
    FOR(i, 0, n) {
    	int x;
    	cin >> x;
    	nMAX = max(nMAX, x);
    	arr.insert(x);
    }
    int res = 0;
    FORE(r, 1, nMAX) {
    	int l = max((ll)1, r - m + 1);
    	int num = distance(lower_bound(arr.begin(), arr.end(), l), upper_bound(arr.begin(), arr.end(), r));
    	if (num < 0) num = 0;
    	if (num >= k) {
    		set<int>::iterator it = upper_bound(arr.begin(), arr.end(), r);
    		it--;
    		arr.erase(it);
    		res++;
    	}
    }
    cout << res << endl;
    return 0;
}