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
#define INFLL 1e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    cin >> n;
    vl s(n), c(n), f(n);
    FOR(i, 0, n) cin >> s[i];
    FOR(i, 0, n) cin >> c[i];
    FOR(i, 0, n) f[i] = c[i];

    vl ff(n, INFLL);
    FOR(i, 0, n) {
        FOR(j, 0, i) {
            if (s[i] > s[j])
                ff[i] = min(ff[i], f[j] + c[i]);
        }
    }   

    f = ff;
    ff = vl(n, INFLL);
    FOR(i, 0, n) {
        FOR(j, 0, i) {
            if (s[i] > s[j])
                ff[i] = min(ff[i], f[j] + c[i]);
        }
    }   

    ll res = INFLL;
    FOR(i, 2, n) res = min(res, ff[i]);
    if (res != INFLL)
        cout << res << endl;
    else {
        cout << -1 << endl;
    }
    return 0;
}