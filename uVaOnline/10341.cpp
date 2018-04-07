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

int p,q,r,s,t,u;
 
double f(double x){
  	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	string input;
    while (getline(cin , input)) {
    	stringstream ss(input);
    	ss >> p >> q >> r >> s >> t >> u;
    	if (f(0)*f(1) > 0) {
    		cout << "No solution" << endl;
    	} else {
    		double low = 0.0, high = 1.0;
    		REP(ii, 0, 50) {
    			double mid = (low+high) / 2.0;
    			if (f(mid) > 0) {
    				low = mid;
    			} else {
    				high = mid;
    			}
    		}
    		printf("%.4f\n", low);
    	}
    	
    }
    return 0;
}