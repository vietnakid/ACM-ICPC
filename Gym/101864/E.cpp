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

const int nMax = 1e7 + 1;

ll power(ll a, ll n, ll mod) {
	if (n == 0 && a != 0) return 1;
    if (n == 0 && a == 0) return 0;
	if (n == 1) return a;
	ll b = power(a, n >> 1, mod);
	ll res = (b * b) % mod;
	if (n & 1) res = (res * a) % mod;
	return res;
}

ll divmod(ll a, ll b, ll mod) { // a div b = a * b^(p-2)
	b = power(b, mod - 2, mod);
	return (a * b) % mod;
} 

ll fac[nMax];

void init() {
    fac[0] = 1;
    fac[1] = 1;
    FOR(i, 2, nMax) {
        fac[i] = (fac[i-1] * i) % nMod;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    init();
    int TC; cin >> TC;
    while (TC--) {
        ll n, m, k;
        cin >> n >> m >> k;
        if (n < k) {
            cout << 0 << endl;
            continue;
        }
        ll mk = power(m, k, nMod);
        ll divi = (fac[n-k] * fac[k]) % nMod;
        ll ckn = divmod(fac[n], divi, nMod);
        ll res = (ckn * mk) % nMod;
        cout << res << endl;
    }
    return 0;
}