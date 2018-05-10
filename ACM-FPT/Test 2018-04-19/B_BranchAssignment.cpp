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

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int n, b, s, m;
vvl arr, brr;
vl d, d1, d2;
vi fre;

void dijkastra() {
	while(true) {
		int u = -1;
		ll minn = INF;

		FOR(i, 1, n+1) {
			if (fre[i] && d[i] < minn) {
				u = i;
				minn = d[i];
			}
		}	
		if (u == -1) {
			return;
		}
		fre[u] = false;
		FOR(i, 1, n+1) {
			if (fre[i] && d[i] > d[u] + arr[u][i]) {
				d[i] = d[u] + arr[u][i];
			}
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
	cin >> n >> b >> s >> m;
	arr = vvl(n+1, vl(n+1, INF) );
	brr = vvl(n+1, vl(n+1, INF));
	FOR(i, 0, m) {
		int x, y, c;
		cin >> x >> y >> c;
		arr[x][y] = c;
		brr[y][x] = c;
	}
	d = vl(n+1, INF);
	fre = vi(n+1, true);
	d[b+1] = 0;
	dijkastra();
	d1 = d;


	arr = brr;
	d = vl(n+1, INF);
	fre = vi(n+1, true);
	d[b+1] = 0;
	dijkastra();
	d2 = d;

	d = vl(n+1, INF);
	FORE(i, 1, b) {
		d[i] = d1[i] + d2[i];
	}
	sort(d.begin(), d.end());

	vl sum(b+1, 0);
	FORE(i, 1, b) {
		sum[i] = sum[i-1] + d[i-1];
	}
	vvl f(n+1, vl(n+1, INFLL));
	f[0][0] = 0;

	FORE(i, 1, b) {
		FORE(k, 1, s) {
			int leng = i/k;
			FOR(j, max(0, i - leng), i) {
				f[i][k] = min(f[i][k], f[j][k-1] + (i-j-1)*(sum[i] - sum[j]));
				// cout << i << " " << j << " " << k << " " << f[i][k] << endl;
			}
		}
	}
	cout << f[b][s] << endl;
    return 0;
}