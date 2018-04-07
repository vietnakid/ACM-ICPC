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
	ios_base::sync_with_stdio(false);
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    while (true) {
    	int n, m;
    	cin >> n >> m;
    	if (n == 0 && m == 0) break;
    	vi arr(n), brr(m);
    	REP(i, 0, n) cin >> arr[i];
    	REP(i, 0, m) cin >> brr[i];
    	sort(arr.begin(), arr.end());
    	sort(brr.begin(), brr.end());
    	int a = 0, b = 0;
    	int res = 0;
    	while (a < n && b < m) {
    		if (a == n) break;
    		while (brr[b] < arr[a] && b < m) b++;
    		if (b == m) break;
    		res += brr[b];
    		a++; b++;
    	}
    	if (a == n) {
    		cout << res << endl;
    	} else {
    		cout << "Loowater is doomed!" << endl;
    	}
    }
    return 0;
}