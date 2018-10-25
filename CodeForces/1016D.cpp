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
    int n, m;
    cin >> n >> m;
    vi ar(n), ac(m);
    FOR(i, 0, n) cin >> ar[i];
    FOR(i, 0, m) cin >> ac[i];
    // check all map
    int sr = 0, sc = 0;
    FOR(i, 0, n) sr ^= ar[i];
    FOR(i, 0, m) sc ^= ac[i];
    vvi res(n, vi(m, 0));
    if (sr != sc) {
        goto wrong;
    }
    res[n-1][m-1] = ar[n-1];
    FOR(i, 0, n-1) {
        res[i][m-1] = ar[i];
    }
    FOR(i, 0, m-1) {
        res[n-1][i] = ac[i];
        res[n-1][m-1] ^= ac[i];
    }
    
    cout << "YES" << endl;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
    wrong: cout << "NO" << endl;
    return 0;
}