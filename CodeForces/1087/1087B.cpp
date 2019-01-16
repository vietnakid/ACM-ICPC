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

#define INF 1000000007
#define INFLL 1000000000000000000
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
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    ll n, k;
    cin >> n >> k;
    ll res = INF;
    for (ll i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            ll j = n / i;
            ll x = i*k + j;
            if ((x/k)*(x%k) == n) {
                // cerr << x << " " << (x/k)*(x%k) << " " << i << " " << j << endl;
                res = min(res, x);
            }
            x = j*k + i;
            if ((x/k)*(x%k) == n) {
                // cerr << x << " " << (x/k)*(x%k) << " " << i << " " << j << endl;
                res = min(res, x);
            }
        }
    }
    cout << res << endl;
    return 0;
}