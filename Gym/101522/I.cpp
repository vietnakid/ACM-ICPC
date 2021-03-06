#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
    int n;
    cin >> n;
    vl arr(n);
    REP(i, 0, n) cin >> arr[i];
    vl change;
    change.push_back(0);
    change.push_back(0);
    REP(i, 1, n) {
    	// cout << abs(arr[i] - arr[i-1]) - abs(-arr[i] - arr[i-1]) << " ";
    	change.push_back(abs(arr[i] - arr[i-1]) - abs(-arr[i] - arr[i-1]));
    }
    // cout << endl;
    ll res = 0;
    REP(i, 1, n) res += abs(arr[i] - arr[i-1]);
    vl::iterator m = max_element(change.begin(), change.end());
    res -= *m;
    change.erase(m);
    m = max_element(change.begin(), change.end());
    res -= *m;
    cout << res << endl;
    return 0;
}
