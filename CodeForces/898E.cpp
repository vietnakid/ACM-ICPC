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
    vi f(31624);
    FORE(i, 0, 31623) f[i] = i*i;
    int n;
    cin >> n;
    vi arr(n, 0);
    int zero = 0;
    FOR(i, 0, n) {
    	int x;
    	cin >> x;
    	if (x == 0) zero++;
    	vi::iterator it = lower_bound(f.begin(), f.end(), x);
    	arr[i] = *it - x;
    	it--;
    	arr[i] = min(arr[i], abs(*it - x));
    }
    sort(arr.begin(), arr.end());
    // FOR(i, 0, n) cout << arr[i] << " ";
    ll res = 0;
    FOR(i, 0, n/2) res += arr[i];

    FOR(i, n/2, n) if (arr[i] == 0) res++;
    if (zero > n/2) 
    	res += zero - n/2;
    cout << res << endl;
    return 0;
}
