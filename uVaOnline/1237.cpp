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

struct car {
	string name;
	int low, high;
};

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int TC;
    cin >> TC;
    while (TC--) {
    	int n;
    	cin >> n;
    	vector<car> arr(n);
    	REP(i, 0, n) {
	    	string name;
	    	int low, high;
	    	cin >> name >> low >> high;
	    	arr[i] = car{name, low, high};
	    }
	    int m;
	    cin >> m;
	    REP(i, 0, m) {
	    	int p; cin >> p;
	    	int cnt = 0;
	    	string res;
	    	for(int i = 0; i < n && cnt <= 1; i++)
	    		 if (arr[i].low <= p && p <= arr[i].high) {
	    		 	cnt++;
	    		 	res = arr[i].name;
	    		 }

	    	if (cnt != 1) {
		    	cout << "UNDETERMINED" << endl;
		    } else {
		    	cout << res << endl;
		    }
	    }
	    if (TC) {
	    	cout << endl;
	    }
    }
    return 0;
}
