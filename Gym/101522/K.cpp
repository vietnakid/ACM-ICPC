#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    bitset<4> corner;
    corner.reset();
    REP(i, 0, k) {
    	int x, y;
    	cin >> x >> y;
    	if (x == 1 && y == 1) corner[0] = true;
    	if (x == 1 && y == m) corner[1] = true;
    	if (x == n && y == 1) corner[2] = true;
    	if (x == n && y == m) corner[3] = true;
    } 
    int res = 4;
    REP(i, 0, 4) if (corner[i]) res--;
    if (n== 1 || m == 1) res /= 2;
    if (n == 1 && m == 1 && res > 0) res = 1;
    cout << res << endl;
    return 0;
}
