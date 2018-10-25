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

ll x, y, d;

void extendedEuclid(ll a, ll b) { 
    if (b == 0) { x = 1; y = 0; d = a; return; }
    extendedEuclid(b, a % b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        int c1, m1, c2, m2;
        cin >> c1 >> m1 >> c2 >> m2;
        if (n % GCD(m1, m2) != 0) {
            cout << "failed" << endl;
        } else {
            extendedEuclid(m1, m2);
            ll t = n / d;
            // cerr << x*t << " " << y*t << endl;
            ll lower = ceil(-double(x*t) / double(m2/d));
            ll upper = floor(double(y*t) / double(m1/d));
            // cerr << lower << " " << upper << endl;
            if (upper < lower) {
                cout << "failed" << endl;
                continue;
            } else {
                ll r1, r2;
                ll C1 = c1 * ((m2/d));
                ll C2 = c2 * ((m1/d));
                // cerr << C1 << " " << C2 << endl;
                if (C1 <= C2) {
                    r1 = x*t + upper*(m2/d);
                    r2 = y*t - upper*(m1/d);
                } else {
                    r1 = x*t + lower*(m2/d);
                    r2 = y*t - lower*(m1/d);
                }
                
                cout << r1 << " " << r2 << endl;
            }
        }
    }
    return 0;
}