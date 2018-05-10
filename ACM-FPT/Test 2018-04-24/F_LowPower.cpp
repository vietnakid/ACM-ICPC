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

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int n, m;
vi arr;

bool canTry(int d) {
	int numPair = 0;
	int boundIndex = 0;
	FOR(index, 0, 2*n*m - 1) {
		if (arr[index+1] - arr[index] <= d) {
			numPair++;
			if (numPair == n)
				return true;
			index++;
			boundIndex += 2*m;
			continue;
		}
		if (index >= boundIndex) {
			return false;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    
    cin >> n >> m;
    arr = vi(2*n*m);
    FOR(i, 0, 2*n*m) {
    	cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int low = 0, high = INF;
    FOR(t, 0, 100) {
    	int mid = (low + high) / 2;
    	if (canTry(mid)) {
    		high = mid;
    	} else {
    		low = mid+1;
    	}
    }
    cout << low << endl;
    return 0;
}