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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int s11 = 0, s0 = 0;
    FOR(i, 0, n) {
        if (a[i] == '1' && b[i] == '1') {
            s11++;
        }
        if (a[i] == '0') {
            s0++;
        }
    }
    // cerr << s11 << " " << s0 << endl;
    ll res = 0;
    FOR(i, 0, n) {
        if (b[i] == '0') {
            if (a[i] == '0') {
                res += s11;
            } else {
                res += s0;
            }
        }
    }
    cout << res << endl;
    return 0;
}