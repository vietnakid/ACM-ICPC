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
    while (true) {
    	int n;
    	cin >> n;
    	if (n==0) break;
    	map<int, int> arr;
    	int maxx = 0;
    	REP(i, 0, n) {
    		int x;
    		cin >> x;
    		arr[x]++;
    		maxx = max(maxx, arr[x]);
    	}
    	cout << maxx << endl;
    	vvi res(maxx);
    	ll index = 0;
    	for (map<int, int>::iterator it = arr.begin(); it!=arr.end(); it++) {
    			while ((*it).second != 0) {
    				(*it).second--;
    				res[index % maxx].push_back((*it).first);
    				index++;
    			}
    	}
    	REP(i, 0, maxx) {
    		REP(j, 0, res[i].size()) {
    			if (j > 0) cout << " ";
    			cout << res[i][j];
    		}
    		cout << endl;
    	}
    }
    return 0;
}