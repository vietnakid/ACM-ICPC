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
	int nMAX = 251;
	vvl arr(nMAX);
	REP(i, 0, nMAX) {
		arr[i] = vl(nMAX, 0);
		arr[i][i] = 1;	
	} 

	REP(i, 1, nMAX) {
		REP(j, 1, i) {
			int sum = i - j;
			REP(k, 1, j+1) {
				if (k <= sum)
				arr[i][j] += arr[sum][k];
				// cout << "wtf " << sum << " " << k << " =  " << arr[sum][min(sum, k)] << endl;
			}
			// cout << i << " " << j << " " << arr[i][j] << endl;
		}
	}

	REP(i, 1, nMAX) {
		REP(j, 2, nMAX) {
			arr[i][j] += arr[i][j-1];
		}
	}

    while (true) {
    	int n;
    	cin >> n;
    	if (n==0) break;
    	
    	ll res = 1;
    	REP(i, 1, n+1) {
    		int sum = (n - i);
    		if (!(sum & 1))
    			res += arr[sum/2][i];
    		// cout << i << " " << res << " " << arr[sum/2][i] << endl;
    	}
    	// cout << res << endl;
    	if (!(n & 1)) {
    		res += arr[n/2][n/2];
    	}

    	cout << res << endl;
    }
    return 0;
}