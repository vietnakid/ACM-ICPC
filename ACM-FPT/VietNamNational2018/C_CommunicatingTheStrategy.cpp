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
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll powMod(ll a, ll n, ll mod) {
	if (n == 0 && a != 0) return 1;
    if (n == 0 && a == 0) return 0;
	if (n == 1) return a;
	ll b = powMod(a, n >> 1, mod);
	ll res = (b * b) % mod;
	if (n & 1) res = (res * a) % mod;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int n;
    cin >> n;
    vl arr(n+1, 0);
    vl f(n+1, 0);
    f[0] = 1;
    cout << "1 1 1" << endl;
    cout << flush;
    ll k, s;
    cin >> k >> s;
    arr[1] = s;
    f[1] = s;
    FORE(i, 2, n) {
        cout << "1 1 " << i << endl;
        cout << flush;
        cin >> k >> s;
        arr[i] = (((s - f[k] + nMod) % nMod) * powMod(f[k-1], nMod-2, nMod)) % nMod;
        FORD(j, i, 1) {
            f[j] = (f[j] + f[j-1]*arr[i] % nMod) % nMod;
        }
        // cerr << arr[i] << endl;
    }
    cout << 2 << " ";
    FORE(i, 1, n) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}