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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    while (true) {
    	int n, x, t, k;
    	cin >> n >> x >> t >> k;
    	if (n == 0 && x == 0 && t == 0 && k == 0) break;

    	int scost;
    	FORE(i, 0, x*(n+1)) {
    		int s = i + t*(n+1);
    		int s10 = ceil((double)s*0.1);
    		if (s + s10 <= x*(n+1)) scost = i;
    	}
    	vi p(2*k), v(2*k, 0);
    	FOR(i, 0, k) {
    		cin >> p[i];
    		FOR(j, 0, n+1) {
    			int x;
    			cin >> x;
    			v[i] += x;
    		}

    		p[i+k] = p[i];
    		v[i+k] = v[i];
    	}

    	int f[k*2][2*(n+1)+1][scost+1];
    	memset(f, 0, sizeof(f));
    	int res = 0;
    	FOR(i, 0, k*2)
    	 FORE(j, 0, 2*(n+1))
    	  FORE(c, 0, scost) {
    	      if (i == 0) {
    	      	  if (j == 1 && c == p[0]) f[i][j][c] = v[0];
    	      } else {
    	          f[i][j][c] = f[i-1][j][c];
    	          if (j > 0) {
    	          	  if (c-p[i] >= 0)
    	          		f[i][j][c] = max(f[i][j][c], f[i-1][j-1][c-p[i]] + v[i]);
    	          }
    	      }
    	      res = max(res, f[i][j][c]);
    	  }
    	printf("%.2f\n", (double)res/(n+1));
    }
    return 0;
}