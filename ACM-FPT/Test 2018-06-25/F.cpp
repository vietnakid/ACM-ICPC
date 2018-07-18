#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    ll res = 0;
    int n;
    cin >> n;
    ll ma = 0, mi = 0;
    int m;
    cin >> m;
    vi arr(m);
    FOR(j, 0, m) cin >> arr[j];
    ma = *max_element(arr.begin(), arr.end());
    mi = *min_element(arr.begin(), arr.end());
    FOR(i, 1, n) {
        int m;
        cin >> m;
        vi arr(m);
        FOR(j, 0, m) cin >> arr[j];
        ma = *max_element(arr.begin(), arr.end());
        res += i*abs(ma - mi);
        mi = *min_element(arr.begin(), arr.end());
    }
    cout << res << endl;
    return 0;
}