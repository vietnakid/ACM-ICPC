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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    ll n, m;
    while (cin >> n >> m) {
        int diff = 0;
        ll res = 1;
        FORE(i, n-m+1, n) {
            ll x = i;
            while (x % 2 == 0) {
                diff++;
                x /= 2;
            }
            while (x % 5 == 0) {
                diff--;
                x /= 5;
            }
            res = (res * x) % 10;
        }
        if (diff > 0) {
            FOR(i, 0, diff) {
                res = (res * 2) % 10;
            }
        } else {
            diff = -diff;
            FOR(i, 0, diff) {
                res = (res * 5) % 10;
            }
        }
        cout << res << endl;
    }
    return 0;
}