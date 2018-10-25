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
    while (true) {
        ll n;
        cin >> n;
        if (n == 0) break;
        int m = sqrt(n);
        // cerr << m << endl;
        int x, y;
        int d = n - (m*m) - 1;
        int l = m+1;
        if (m & 1) {
            x = 1; y = m;
            if (n != m*m) {
                y++;
                if (d < l) {
                    x += d;
                } else {
                    x += l-1;
                    d -= l-1;
                    y -= d;
                }
            }
            cout << x << " " << y << endl;
        } else {
            x = m; y = 1;
            if (n != m*m) {
                x++;
                if (d < l) {
                    y += d;
                } else {
                    y += l-1;
                    d -= l-1;
                    x -= d;
                }
            }
            cout << x << " " << y << endl;
        }
    }
    return 0;
}