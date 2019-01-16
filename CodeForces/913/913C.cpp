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
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
    int n;
    ll l;
    cin >> n >> l;
    vl arr(31, INFLL);
    FOR(i, 0, n) cin >> arr[i];
    FOR(i, 0, 31)
    	if (arr[i] * 2 < arr[i+1]) {
    		arr[i+1] = arr[i] * 2;
    	}

    for (int i = 30; i > 0; i--) {
    	if (arr[i] < arr[i-1]) {
    		arr[i-1] = arr[i];
    	} 
    }
    
    ll res = 0;

    int highbit = 0;
    FOR(i, 0, 30) {
    	if (1 << i & l) {
    		res += arr[i];	
    	} 
    	if (res > arr[i+1]) {
    		res = arr[i+1];
    	}
    }

    cout << res << endl;
    return 0;
}