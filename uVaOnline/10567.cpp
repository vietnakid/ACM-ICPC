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

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    string s;
    cin >> s;
    vvi arr(256);
    int n = s.size();
    REP(i, 0, n) {
    	arr[s[i]].push_back(i);
    }
    int q;
    cin >> q;
    while (q--) {
    	string ss; cin >> ss;
    	n = ss.size();
        int index = 0;
    	bool check = true;
    	REP(i, 0, n) {
            char x = ss[i];
            vi::iterator it = upper_bound(arr[x].begin(), arr[x].end(), index);
            if (it == arr[x].end()) {
    			check = false;
    			break;
    		} else {
                index = *it;
            }
    	}
    	if (!check) {
    		cout << "Not matched" << endl;
    	} else {
    		cout << "Matched " << *upper_bound(arr[ss[0]].begin(), arr[ss[0]].end(), 0) << " " << index << endl;
    	}
    }
    return 0;
}