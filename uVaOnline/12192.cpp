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

vvi arr;
int l, r;
int n, m;

int sovle() {
	int res = 0;
	REP (i, 0, n) {
		int posi = distance(arr[i].begin(), lower_bound(arr[i].begin(), arr[i].end(), l));
		int low = 0, high = min(n, m);
		int x = i, y = posi, xx, yy;
		while (low <= high) {
			int mid = (low + high) / 2;
			xx = x + mid;
			yy = y + mid;
			// cout << "mid = " << mid << " xx = " << xx << " yy = " << yy << endl;
			if (xx < n && yy < m && arr[xx][yy] <= r) {
				res = max(res, mid + 1);
				low = mid + 1;
				// cout << x << " " << y << " " << xx << " " << yy << endl;
			} else {
				high = mid - 1;
			}
		}
	}
	return res;
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    while (true) {
    	cin >> n >> m;
    	if (n == 0 && m == 0) break;
    	arr = vvi(n);
    	REP(i, 0, n) arr[i] = vi(m);
    	REP(i, 0, n)
    		REP(j, 0, m)
    			cin >> arr[i][j];
    	int q;
    	cin >> q;
    	REP(ii, 0, q) {
    		cin >> l >> r;
    		cout << sovle() << endl;
    	}
    	cout << "-" << endl;
    }
    return 0;
}