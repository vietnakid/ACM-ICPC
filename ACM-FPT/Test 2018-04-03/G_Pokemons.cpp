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

#define INF 2e10 // 2e9
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
	// freopen("input", "r", stdin);d
	// freopen("output", "w", stdout);
	double m, mm;
	cin >> m;
	int n;
	cin >> n;
	double mi = -INF, res = -INF;
	FOR(i, 0, n) {
		cin >> mm;
		res = max(res, (mm*mi) - m);
		mi = max(mi, m/mm);
	}
	if (res >= 0)
		res = (res+0.00001) * 100;
	else
		res = (res-0.00001) * 100;
	res = round(res);
	res = res / 100.0;
	printf("%0.2lf\n", res);
    return 0;
}