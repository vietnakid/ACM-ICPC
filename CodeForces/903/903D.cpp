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
	freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int n;
    cin >> n;
    map<ll, int> m;
    vl arr(n), f(n);

    FOR(i, 0, n) {
    	ll x;
    	cin >> x;
    	m[x]++;
    	arr[i] = x;
    	if (i == 0) f[i] = arr[i];
    	else f[i] = f[i-1] + arr[i];
    }

	ll res = 0;
    FOR(i, 0, n) {
    	int numGreater = m[arr[i] + 1];
    	int numLess = m[arr[i] - 1];
    	ll numRest = n - i - 1;
    	m[arr[i]]--;	
    	res += (f[n-1] - f[i]) - numRest * arr[i];
    	res -= numGreater;
    	res += numLess;
    }
    cout << res << endl;
    return 0;
}