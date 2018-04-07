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

#define isOn(S, j) (S & (1 << j))

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int countbit(int x) {
	int res = 0;
	REP(i, 0, 21) {
		if (isOn(x, i)) res++;
	}
	return res;
}

int main()
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
 	int TC = 0;
    while (true) {
    	int n, m;
		cin >> n >> m;
    	if (n==0 && m==0) break;
    	TC++;
    	vi arr(n);
    	REP(i, 0, n) cin >> arr[i];
    	int k; cin >> k;
    	vi p(k);
    	vector<set<int> > serve(k);
    	REP(ii, 0, k) {
    		int h; cin >> h;
    		REP(i, 0, h) {
    			int x;
    			cin >> x;
    			x--;
    			serve[ii].insert(x);
    		}
    		cin >> p[ii];
    	}
    	int res = 0, respos;

    	REP(ii, 0, 1<<n) {
    		vi select;
    		int total = 0;
    		if (countbit(ii) == m) {
    			
    			REP(i, 0, n) {
    				if (isOn(ii, i)) {
    					select.push_back(i);
    					total += arr[i];
    				}
    			}
    		

	    		REP(i ,0, k) {
	    			int cnt = 0;
	    			REP(j, 0, m) {
	    				if (serve[i].find(select[j]) != serve[i].end()) cnt++;
	    			}
	    			if (cnt > 1) total -= p[i]*(cnt-1);
	    		}

	    		if (res < total) {
	    			res = total;
	    			respos = ii;
	    		}
	    	}
    	}
    	cout << "Case Number  " << TC << endl;
    	cout << "Number of Customers: " << res << endl;
    	cout << "Locations recommended:";
    	REP(i, 0, n) 
    		if (isOn(respos, i)) cout << " " << i+1;
    	cout << endl << endl;
    }
    return 0;
}
