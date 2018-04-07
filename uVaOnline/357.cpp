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

ll f[30001][5];

ll cal(int n, int min) {
	if (f[n][min] != 0) return f[n][min];
	ll way = 0;
	if (n - 1 >= 0 && min >= 0) way += cal(n-1, 0);
	if (n - 5 >= 0 && min >= 1) way += cal(n-5, 1);
	if (n - 10 >= 0 && min >= 2) way += cal(n-10, 2);
	if (n - 25 >= 0 && min >= 3) way += cal(n-25, 3);
	if (n - 50 >= 0 && min >= 4) way += cal(n-50, 4);
	f[n][min] = way;
	return f[n][min];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	memset(f, 0, sizeof(f));
	f[0][0] = 1; f[0][1] = 1; f[0][2] = 1; f[0][3] = 1; f[0][4] = 1;

    while (true) {
    	int n = -INF;
    	cin >> n;
    	if (n == -INF) break;

    	ll way = cal(n, 4);
    	if (way > 1) {
    		printf("There are %lld ways to produce %lld cents change.\n", way, n);
    	} else {
    		printf("There is only 1 way to produce %lld cents change.\n", n);
    	}
    }
    return 0;
}