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
    while (true) {
    	int f, r;
    	cin >> f >> r;
    	if (f == 0) break;
    	vector<double> af(f), ar(r);
    	REP(i, 0, f) cin >> af[i];
    	REP(i, 0, r) cin >> ar[i];
    	vector<double> arr;
    	REP(i, 0, f)
    		REP(j, 0, r)
    			arr.push_back(ar[j] / af[i]);
    	sort(arr.begin(), arr.end());
    	double res = 0;
    	REP(i, 1, arr.size()) res = max(res, arr[i] / arr[i-1]);
    	printf("%.2f\n", res);
    }
    return 0;
}
