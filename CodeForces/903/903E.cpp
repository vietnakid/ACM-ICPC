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

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
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
    int k, n;
    cin >> k >> n;
    vector<string> arr(k);
    FOR(i, 0, k) cin >> arr[i];
    FOR(i, 0, n)
    	FOR(j, i+1, n) {
            if (arr[0][i] != arr[0][j]) {
    		string s = arr[0];
    		char tmp = s[i];
    		s[i] = s[j];
    		s[j] = tmp;
    		bool ok = true;
    		FOR(ii, 1, k) {
    			int d = 0;
    			FOR(jj, 0, n)
    				if (s[jj] != arr[ii][jj]) d++;
    			if (d > 2) ok = false;
    		}
    		if (ok) {
    			cout << s << endl;
    			return 0;
    		}
    	}
    }
    cout << -1 << endl;
    return 0;
}