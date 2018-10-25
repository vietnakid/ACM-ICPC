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
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    vl f(1000001, 0);
    FOR(i, 2, 1000001) {
        f[i] = f[i-1] + i * (i-1) * 2;
    }
    while (true) {
        ll n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        if (n > m) {
            ll tmp = n;
            n = m;
            m = tmp;
        }
        ll res = (m-1)+(n-1);
        res *= m*n;
        ll res2 = f[n-1];
        cerr << res << endl;
        res2 += n * (n-1) * (m-n+1);
        res += res2 + res2;
        cerr << res2 << endl;
        cout << res << endl;
    }
    return 0;
}