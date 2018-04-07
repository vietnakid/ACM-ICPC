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

int n, s;
vi arr, brr;
vvi f;

int cal(int x, int y) {
	int res = 1000000;
	if (x == 0 && y == 0) return 0;
	if (x < 0 || y < 0) return 1000000;
	if (f[x][y] != 1000000) return f[x][y];
	FOR(i, 0, n) {
		res = min(res, cal(x - arr[i], y - brr[i]));
	}
	res++;
	f[x][y] = res;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int TC; cin >> TC;
    while (TC--) {
    	cin >> n >> s;
    	arr = vi(n); brr = vi(n);
    	FOR(i, 0, n) {
    		cin >> arr[i] >> brr[i];
    	}
    	f = vvi(s+1);
    	FORE(i, 0, s) {
    		f[i] = vi(s+1);
    		FORE(j, 0, s) {
    			f[i][j] = 1000000;
    		}
    	}
    	int res = 1000000;
    	set<int> chinhphuong;
    	FORE(i, 0, 300)
    		chinhphuong.insert(i*i);
    	FORE(i, 0, s) {
    		int j = s*s - i*i;    		
    		if (chinhphuong.find(j) != chinhphuong.end()) {
    			j = sqrt(j);
    			res = min(res, cal(i, j));
    		}
    	}
    	if (res >= 1000000) {
    		cout << "not possible" << endl;
    	} else {
    		cout << res << endl;
    	}
    }
    return 0;
}