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

#define INF 1000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

const int MAXN = 2e5 + 10;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	freopen("input", "w", stdout);
    int n = 2e5;

	cout << n << endl;

	for (int i = 0; i < n - 1; ++i)
		cout << (i < n / 2 ? 1 : INF) << ' '; 
	cout << INF << endl;

	return 0;
}