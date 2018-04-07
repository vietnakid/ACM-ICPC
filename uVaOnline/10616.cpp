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
	int tc = 0;
    while (true) {
    	int n, q;
    	cin >> n >> q;	
    	if (n == 0 && q == 0) break;

    	int arr[n+1];
    	FORE(i, 1, n) cin >> arr[i];
    	tc++;
    	printf("SET %d:\n", tc);
    	FORE(ii, 1, q) {
    		printf("QUERY %d: ", ii);
    		int m, d;
    		cin >> d >> m;
    		int f[n+1][m+1][d];
    		memset(f, 0, sizeof(f));
    		FORE(i, 0, n)
    			f[i][0][0] = 1;
    		FORE(i, 1, n) {
    			FORE(j, 1, m) {
    				FOR(k, 0, d) {
    					f[i][j][k] = f[i-1][j][k];
    					// cout << "----" << endl;
    					// cout << i << " " << j << " " <<  k << " " << f[i][j][k] << endl;
    					// cout << i-1 << " " << j-1 << " " <<  (k - arr[i]%d + d) % d << " " << f[i-1][j-1][(k - arr[i]%d + d) % d] << endl;
    					// cout << "----" << endl;
    					f[i][j][k] += f[i-1][j-1][(k - arr[i]%d + d) % d];
    					// cout << i << " " << j << " " <<  k << " " << f[i][j][k] << endl;
    				}
    			}
    		}
    		printf("%d\n", f[n][m][0]);
    	}
    }
    

    return 0;
}