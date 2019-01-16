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
    int n;
    cin >> n;
    vvi child(n);
    FOR(i, 1, n) {
    	int x;
    	cin >> x;
    	x--;
    	child[x].push_back(i);
    }
    bool check = true;
    FOR(i, 0, n) {
    	if (child[i].size() != 0) {
    		int cnt = 0;
    		// cout << "i = " << i << endl;
    		FOR(j, 0, child[i].size()) {
    			int u = child[i][j];
    			if (child[u].size() == 0) cnt++;
    		}
    		if (cnt < 3) check = false;
    		// cout << "cnt = " << cnt << endl;
    	}
    }
    if (check) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
    return 0;
}