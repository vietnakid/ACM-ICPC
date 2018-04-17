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

int main()
{
	cin.tie();
	// freopen("input", "r", stdin);d
	// freopen("output", "w", stdout);
	int t; cin >> t;
	FOR(i, 0, t) {
		ll n, k;
		cin >> k >> n;
		ll s1, s2, s3;
		s1 = (n*(n+1)) / 2;
		s2 = n*n;
		s3 = (n*n) + n;
		cout << k << " " << s1 << " " << s2 << " " << s3 << endl;
	}
    return 0;
}