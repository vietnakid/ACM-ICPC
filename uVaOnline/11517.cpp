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

int sum, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int TC;
    cin >> TC;
    int maxN = 10000;
    while (TC--) {
    	cin >> sum >> n;
    	int arr[n+1];
    	FORE(i, 1, n) cin >> arr[i];
    	int f[n+1][2*maxN + 1];
    	FORE(ii, 0, n)
    		FORE(i, 0, 2*maxN) 
    			f[ii][i] = INF;
    	f[0][0] = 0;
    	FORE(ii, 1, n)
    		FORE(i, 0, 2*maxN) {
    			f[ii][i] = f[ii-1][i];
    			int s = i - arr[ii];
    			if (s >= 0) {
    				f[ii][i] = min(f[ii][i], f[ii-1][s] + 1);
    			}
    		}
    	FORE(i, sum, 2*maxN) {
    		if (f[n][i] < INF) {
    			cout << i << " " << f[n][i] << endl;
    			break;
    		}
    	}
    }
    return 0;
}