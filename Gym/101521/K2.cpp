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
#define esp 0.0000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

ll cal(ld r) {
	ll res = 0;
	ld R = r*r;
	for(ll y = 1; y <= r; y++) {
		res += sqrt(R - y*y) + 1;
		printf("with R = %d and y = %d have %d\n", r, y, R - y*y);
	}
	return res * 4 + 1;
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    ll r, d;
    cin >> r >> d;
    ll res2 = cal(r+d), res1 = 0;
    if (r > d) res1 = cal(r-d-esp);
    // cout << res2 << " " << res1 << endl;
    cout << res2 - res1 << endl;
    return 0;
}