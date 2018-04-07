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
	string s;
    while (getline(cin, s)) {
    	stringstream ss(s);
    	int k;
    	ss >> k;
    	int res = 0;
    	REP(x, k+1, 2*k+1) {
    		int y = (k*x % (x-k) == 0) ? k*x / (x-k) : 0;
    		if (y >= x)
    			res++;
    			
    	}
    	cout << res << endl;
    	REP(x, k+1, k*10) {
    		int y = (k*x % (x-k) == 0) ? k*x / (x-k) : 0;
    		if (y >= x)
    			printf("1/%d = 1/%d + 1/%d\n", k, y, x);
    	}
    }
    return 0;
}
