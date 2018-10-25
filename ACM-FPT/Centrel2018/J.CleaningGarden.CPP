#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1e9+7
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll res = INFLL;
int n, k;
vl arr;

void solve() {
    ll s = 0;
    s = abs(arr[0]);
    FOR(i, 1, k) {
        s += abs(arr[i] - arr[i-1]);
    }
    res = min(res, s);
    // cerr << s << endl;
    FOR(i, k, n) {
        int j = i-k+1;
        s += abs(arr[i] - arr[i-1]);
        s -= abs(arr[j] - arr[j-1]);

        s -= abs(arr[j-1]);
        s += abs(arr[j]);

        res = min(res, s);
        // cerr << s << endl;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    
    cin >> n >> k;
    arr.resize(n);
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    solve();
    sort(arr.rbegin(), arr.rend());
    solve();

    cout << res << endl;
    return 0;
}