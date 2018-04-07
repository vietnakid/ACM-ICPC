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

int solve(vi & arr) {
	int n = arr.size();
	if (n == 2) return arr[1] - arr[0];
	int res = max(arr[1] - arr[0], arr[2] - arr[0]);
	res = max(res, arr[n-1] - arr[n-2]);
	res = max(res, arr[n-1] - arr[n-3]);
	
	for (int i = 3; i < n; i += 2) {
		res = max(res, arr[i] - arr[i-2]);
	}
	for (int i = 4; i < n; i += 2) {
		res = max(res, arr[i] - arr[i-2]);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int TC;
    cin >> TC;
    FORE(tc, 1, TC) {
    	int n, d, res = 0;
    	cin >> n >> d;
    	vi arr;
    	arr.push_back(0);
    	FOR(i, 0, n) {
    		char c, cc; int x;
    		string s;
    		cin >> s;
    		stringstream ss(s);
    		
    		ss >> c >> cc >> x;

    		arr.push_back(x);
    		if (c == 'B') {
    			res = max(res, solve(arr));
    			arr.clear();
    			arr.push_back(x);
    		}
    	}
    	arr.push_back(d);
    	res = max(res, solve(arr));
    	printf("Case %d: %d\n", tc, res);
    }
    return 0;
}