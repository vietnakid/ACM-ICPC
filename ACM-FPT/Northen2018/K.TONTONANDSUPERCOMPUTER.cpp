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

ll mulmod(ll a, ll n, ll mod) {
    if (n == 0) return 0;
	if (n == 1) return a;
	ll b = mulmod(a, n >> 1, mod);
	ll res = (b + b) % mod;
	if (n & 1) res = (res + a) % mod;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n, m; 
    cin >> n >> m;
    ll M; 
    cin >> M;
    vl arr(n), brr(m);
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    FOR(i, 0, m) {
        cin >> brr[i];
    }
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            ll g = GCD(arr[i], brr[j]);
            arr[i] /= g;
            brr[j] /= g;
        }
    }
    ll resa = 1, resb = 1;
    FOR(i, 0, n) {
        resa = mulmod(resa, arr[i], M);
    }
    FOR(j, 0, m) {
        resb = mulmod(resb, brr[j], M);
    }
    cout << resa << endl << resb << endl;
    return 0;
}