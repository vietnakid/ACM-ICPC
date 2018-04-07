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
#define esp 0.0000000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	
    while (true) {
    	int n, d, r;
    	cin >> n >> d >> r;
    	if (n == 0 && r == 0 && d == 0) break;
    	vi arr(n), brr(n);
    	REP(i, 0, n) cin >> arr[i];
    	REP(i, 0, n) cin >> brr[i];
    	sort(arr.begin(), arr.end());
    	sort(brr.rbegin(), brr.rend());
    	int res = 0;
    	REP(i, 0, n) {
    		if (arr[i] + brr[i] > d) {
    			res += (arr[i] + brr[i] - d) * r;
    		}
    	}
    	cout << res << endl;
    }
    return 0;
}