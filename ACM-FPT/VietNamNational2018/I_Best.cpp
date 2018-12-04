#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define FOR(i, a, b) \
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

set<ll> res;
int n, k;
vii attack, def, hel;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> k;
    FOR(i, 0, n) {
        ll a, b, c;
        cin >> a >> b >> c;
        attack.push_back({a, i});
        def.push_back({b, i});
        hel.push_back({c, i});
    }
    sort(attack.rbegin(), attack.rend());
    sort(def.rbegin(), def.rend());
    sort(hel.rbegin(), hel.rend());
    FOR(i, 0, k) {
        res.insert(attack[i].second);
        res.insert(def[i].second);
        res.insert(hel[i].second);
        // cerr << attack[i].first << " " << attack[i].second << endl;
        // cerr << def[i].first << " " << def[i].second << endl;
        // cerr << hel[i].first << " " << hel[i].second << endl;
    }
    cout << res.size() << endl;
    return 0;
}