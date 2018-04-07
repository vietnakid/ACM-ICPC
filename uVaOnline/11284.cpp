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

int n, m, k;
vector< vector<double> > f;
vector< vector<double> > arr;
vi brr;
vector<double> crr;

void fordBellman() {
	FORE(k, 0, n) {
		FORE(i, 0, n)
			FORE(j, 0, n)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
	}

}

double cal(int status, int last) {
	int preStatus = status & ~(1 << last);
	if (preStatus == 0) {
		f[status][last] = arr[0][brr[last]];
	}
	if (f[status][last] != INF) return f[status][last];

	double res = INF;
	FOR(j, 0, k) 
    	if (1 << j & preStatus) {
    		res = min(res, cal(preStatus, j) + arr[brr[last]][brr[j]]);
    	}
    f[status][last] = res;
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
    	cin >> n >> m;
    	arr = vector< vector<double> >(n+1);
    	FORE(i, 0, n) arr[i] = vector<double>(n+1, INF);
    	FORE(i, 0, n) arr[i][i] = 0;
    	FOR(i, 0, m) {
    		int x,y;
    		double d;
    		cin >> x >> y >> d;
    		arr[x][y] = min(arr[x][y], d);
    		arr[y][x] = min(arr[y][x], d);
    	}
    	// fordBellman();
    	cin >> k;
    	f = vector< vector<double> >(1 << k);
    	FOR(i, 0, 1<<k) f[i] = vector<double>(k, INF);
    	brr = vi(k);
    	crr = vector<double>(k);

    	FOR(i, 0, k) {
    		cin >> brr[i] >> crr[i];
    	}

    	double res = 0;
    	FOR(i, 0, 1<<k) {
    		double _res = 0;
    		FOR(j, 0, k) 
    			if (1 << j & i) {
	    			_res += crr[j];
    			}
    		FOR(j, 0, k) 
    			if (1 << j & i) {
	    			double r = cal(i, j);
	    			r += arr[brr[j]][0];
	    			res = max(res, _res - r);
    			}
    	}
    	if (res > 0) {
    		printf("Daniel can save $%.2lf\n", res);
    	} else {
    		printf("Don't leave the house\n");
    	}
    }
    return 0;
}