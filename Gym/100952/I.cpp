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

int n;

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	int TC = 0;
    while (true) {
    	ll n, x, y;
    	cin >> n >> x >> y;
    	if (n == 0 && x == 0 && y == 0) break;
    	TC++;
    	cout << "Case " << TC << ":" <<endl;
    	vvl arr(2);
    	ll minn = 1;
    	REP(i, 0, 2)
    		REP(j, 0, n) {
    			ll x;
    			cin >> x;
    			// minn = min(minn, x);
    			arr[i].push_back(x);
    		}
    	bool isOk = false; 

    	REP(i, 0, n) {
    		if (arr[1][i] == minn) {
    			vvl tmp = arr;
    			int xx = 2;
    			int yy = i+1;
    			
    			bool isCan = true;
    			ll du = minn;
    			ll cnt = 0;
    			REP(ii, 0, 2*n) {
    				if (xx == x && yy == y) {
    					du--;
    				}
    				if (xx = 2) {
    					yy++;
    					if (yy == n+1) {
    						yy = n;
    						xx = 1;
    					}
    				} else {
    					yy--;
    					if (yy == 0) {
    						yy = 1;
    						xx = 2;
    					}
    				}
    				cnt += du;
    				tmp[xx][yy] -= du;
    				if (tmp[xx][yy] < 0) isCan = false;
    				cout << xx << " " << yy << " " << du << endl;
    			}
    			tmp[2][i] = cnt;
    			if (isCan) {
    				isOk = true;
    				REP(i, 0, 2) {
    					REP(j, 0, n) printf("%lld ", tmp[i][j]);
    					cout << endl;
    				}
    				break;
    			}
    		}
    	}
    	if (!isOk) {
    		cout << "INVALID" << endl;
    	}
    }
    return 0;
}