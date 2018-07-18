#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    string a,b;
    cin >> a >> b;
    vi c1(26), c2(26);
    FOR(i, 0, a.size()) {
        c1[a[i]-'a']++;
    }
    FOR(i, 0, b.size()) {
        c2[b[i]-'a']++;
    }
    int res = 0;
    FOR(i, 0, 26) {
        // cerr << c1[i] << " " << c2[i] << endl;
        if (c1[i] >= c2[i]) {
            res += c1[i] - c2[i];
        } else {
            res = -INF;
        }
    }
    if (res >= 0) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}