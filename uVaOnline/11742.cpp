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

    while (true) {
    	int n, m;
    	cin >> n >> m;
    	if (n == 0 && m == 0) break;
    	vi p(n);
    	REP(i, 0, n) p[i] = i;
    	int res = 0;
    	vi a(m), b(m), c(m);
    	REP(i, 0, m) {
    		cin >> a[i] >> b[i] >> c[i];
    	}
    	do {
    		bool ok = true;
    		REP(i, 0, m) {
    			int pa, pb, pc = abs(c[i]);
    			REP(j, 0, n) {
    				if (p[j] == a[i]) pa = j;
    				if (p[j] == b[i]) pb = j;
    			}
    			if (c[i] > 0) {
    				if (abs(pa - pb) > pc) ok = false;
    			} else {
    				if (abs(pa - pb) < pc) ok = false;
    			}
    		}
    		if (ok) res++;
    	} while (next_permutation(p.begin(), p.end()));
    	cout << res << endl;
    }
    return 0;
}
