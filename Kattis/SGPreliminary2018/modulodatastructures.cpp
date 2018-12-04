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
    int n, q;
    cin >> n >> q;
    vl f(n+1, 0);
    vvl ff(450, vl(450, 0));
    FOR(i, 0, q) {
        int c;
        cin >> c;
        if (c == 1) {
            int a, b, t;
            cin >> a >> b >> t;
            if (b >= 450) {
                int x = a;
                while (x <= n) {
                    f[x] += t;
                    x += b;
                }
            } else {    
                ff[b][a] += t;
            }
        } else {
            int x;
            cin >> x;
            ll res = f[x];
            FOR(ii, 1, 450) {
                res += ff[ii][x % ii];
                // cerr << x << " " << ii << " " << x % ii << endl;
            }
            cout << res << endl;
        }
    }
    return 0;
}