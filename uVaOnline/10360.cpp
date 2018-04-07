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
    int TC; cin >> TC;
    while (TC--) {
    	int d, n;
    	cin >> d >> n;
    	vvi arr(1100);
    	REP(i, 0, 1100) arr[i] = vi(1100, 0);
    	REP(ii, 0, n) {
    		int x, y, s;
    		cin >> x >> y >> s;
    		for(int i = max(1, x-d); i <= min(1025, x+d); i++)
    			for(int j = max(1, y-d); j <= min(1025, y+d); j++)
    				arr[i][j] += s;
    	}
    	int res = 0, resx = 0, resy = 0;
    	REP(i, 1, 1026)
    		REP(j, 1, 1026) {
    			if (arr[i][j] > res) {
    				res = arr[i][j];
    				resx = i;
    				resy = j;
    			}
    		}
    	cout << resx << " " << resy << " " << res << endl;
    }
    return 0;
}
