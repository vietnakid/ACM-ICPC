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

inline bool isOn(ll s, ll i) {return s & (1 << i);};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    string s;
    while (getline(cin, s)) {
    	stringstream ss(s);
    	int s, d;
    	ss >> s >> d;
    	int res = -INF;
    	vi arr(12, 0), sum(13, 0);
    	REP(i, 0, 1 << 12) {
    		int total = 0;
    		REP(j, 0, 12)
    			if (isOn(i, j)) {
    				arr[j] = s;
    				total += s;
    			} else {
    				arr[j] = -d;
    				total -= d;
    			}
    		REP(j, 1, 13)
    			sum[j] = sum[j-1] + arr[j-1];
    		int cnt = 0;
    		REP(j, 5, 13) if (sum[j] - sum[j-5] < 0) cnt++;
    		// cout << cnt << endl;
    		if (cnt == 8) {
				// TRvi(arr, it) cout << *it << " ";
				// cout << endl;
				// TRvi(sum, it) cout << *it << " ";
				// cout << endl << endl;
    			res = max(res, total);
    		}
    	}
    	if (res >= 0)
    		cout << res << endl;
    	else 
    		cout << "Deficit" << endl;
    }
    return 0;
}
