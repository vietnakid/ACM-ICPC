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

ll powMod(ll a, ll p, ll m) {
    if (p == 0) {
        return 1;
    }
    ll x = powMod(a, p / 2, m);
    x = (x * x) % m;
    if (p & 1) {
        x = (x * a) % m;
    }
    return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        ll n, k, c;
        cin >> n >> k >> c;
        ll s = 0;
        FOR(i, 0, n) {
            int x; cin >> x;
            s += x;
        }
        ll r = powMod(n, k-1, c);
        r = (r * k) % c;
        r = (r * s) % c;
        
        cout << "Case " << tc << ": " << r << endl;
    }
    return 0;
}