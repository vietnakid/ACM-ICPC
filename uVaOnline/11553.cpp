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
    int TC;
    cin >> TC;
    while (TC--) {
    	int n;
    	cin >> n;
    	int arr[n][n];
    	int res = INF;
    	REP(i, 0, n) 
    		REP(j, 0, n) cin >> arr[i][j];

    	vi permu(n);
    	REP(i, 0, n)
    		permu[i] = i;
    	do {
    		int total = 0;
    		REP(i, 0, n) total += arr[i][permu[i]];
    		res = min(res, total);
    	} while (next_permutation(permu.begin(), permu.end()));
    	cout << res << endl;
    }
    return 0;
}
