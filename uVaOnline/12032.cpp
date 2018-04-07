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

int n;
vi arr;

bool solve(int x) {
	REP(i, 1, n+1) {
		int dis = arr[i] - arr[i-1];
		if (dis > x) return false;
		if (dis == x) x--;
	}
	return true;
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int TC; cin >> TC;
    REP(tc, 1, TC+1) {
    	cin >> n;
    	arr = vi(n+1);
    	arr[0] = 0;
    	int low = 0, high = 0;
    	REP(i, 1, n+1) {
    		cin >> arr[i];
    	}
    	high = arr[n];
    	int res = 0;
    	while (low <= high) {
    		int mid = (low + high) >> 1;
    		if (solve(mid)) {
    			high = mid - 1;
    			res = mid;
    		} else 
    			low = mid + 1;
    	}
    	cout << "Case " << tc << ": " << res << endl;
    }
    return 0;
}