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

bool isOk(ld k, ld h, ld w) {
	return (k <= w/3 && k <= h) || (k <= h/3 && k <= w) || (k <= h/2 && k <= w/2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);d
	// freopen("output", "w", stdout);
	ld a,b;
	cin >> a >> b;
	ld l = 0, r = min(a,b);
	FOR(ii, 0, 100) {
		ld k = (l + r) / 2;
		if (isOk(k, a, b)) {
			l = k;
		} else {
			r = k;
		}
	}
	printf("%.3llf\n", l);
    return 0;
}