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
ld n, unknow = 0, fres;
ld Ratio = 1.0, ratio1 = 0, ratio2 = 0, ratio3 = 0;
vi know;

ld case1() {
	ld res = 0.0;
	double cnt = 0.0;
	REP(i, (int)fres + 1, n+1) {
		if (know[i] == 2) {
			cnt++;
			res = i;
		}
	}
	ratio1 = cnt / (2.*n - unknow);
	// Ratio -= ratio1;
	return res;
}

ld case2() {
	if (unknow < 1) return 0;
	ld res = 0.0;
	REP(i, fres+1, n+1) {
		if (know[i] == 1) {
			ratio2 = (1./unknow);
			res += i;
			Ratio -= ratio2;	
		} 
	}
	return res;
}

ld case3() {
	
	ld res = 0.0;
	REP(i, fres+1, n+1) {
		if (know[i] == 0) {
			ratio3 = 2.*(1./unknow) * (1./(unknow - 1));
			res += i;
			Ratio -= ratio3;	
		} 
	}
	return res;
}

int main()
{
	freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int r;
    cin >> n >> r;
    vi chests(2*n+1, 0);
    fres = 0;
    REP(i, 0, r-1) {
    	ld a, b, a1, b1;
    	cin >> a >> b >> a1 >> b1;
    	chests[a] = a1;
    	chests[b] = b1;
    	if (fabs(a1 - b1) < esp) {
    		fres = max(fres, a1);
    	}
    }
    know = vi(n+1, 0);
    REP(i, 1, 2*n+1) {
    	if (chests[i] == 0) unknow++;
    	know[chests[i]]++;
    }
    	

	ld res1 = case1();
	ld res2 = case2();
    ld res3 = case3();
    cout << fres << " " << res1 << " " << res2 << " " << res3 << endl;
    cout << Ratio << " " << ratio1 << " " << ratio2 << " " << ratio3 << endl;
    cout << fres*Ratio + res2*ratio2 + res3*ratio3 << " ";
    cout << max(fres*Ratio + res2*ratio2 + res3*ratio3, res1) << endl;
    return 0;
}