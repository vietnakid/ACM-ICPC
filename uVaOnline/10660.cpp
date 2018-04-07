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

int dist(int a, int b) {
	return (abs(a/5 - b/5) + abs(a%5 - b%5));
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int TC; cin >> TC;
    while (TC--) {
    	int n;
    	cin >> n;
    	vi arr(25, 0);
    	
    	REP(i, 0, n) {
    		int x, y, c;
    		cin >> x >> y >> c;
    		arr[x*5 + y] = c;
    	}
    	int res = INF;
    	vi resvi(5);
    	REP(i1, 0, 25)
	    	REP(i2, i1+1, 25)
	    	REP(i3, i2+1, 25)
	    	REP(i4, i3+1, 25)
	    	REP(i5, i4+1, 25) {
	    		int totalDis = 0;
	    		REP(i, 0, 25) {
	    			totalDis += min(dist(i, i1), min(dist(i, i2), min(dist(i, i3), min(dist(i, i4), dist(i, i5))))) * arr[i];
	    		}
	    	//	cout << totalDis << endl;
	    		if (totalDis < res) {
	    			res = totalDis;
	    			resvi[0] = i1; resvi[1] = i2; resvi[2] = i3; resvi[3] = i4; resvi[4] = i5;
	    		}
	    	}
	    cout << resvi[0] << " " << resvi[1] << " " << resvi[2] << " " << resvi[3] << " " << resvi[4] << endl;
    }
    return 0;
}
