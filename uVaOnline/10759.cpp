#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ll;
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

int n, x;

ll f[24][151];

ll cal(int stage, int point) {
    if (stage == n) {
        if (point >= x) return 1;
        else return 0;
    }
    if (f[stage][point] != -1) {
        return f[stage][point];
    }
    ll res = 0;
    FORE(i, 1, 6) {
        res += cal(stage+1, point+i);
    }
    f[stage][point] = res;
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    
    while (cin >> n >> x) {
        if (n== 0 && x == 0) break;
        ll total = 1;
        FOR(i, 0, n) {
            total *= 6;
        }
        memset(f, -1, sizeof(f));
        ll res = cal(0, 0);
        ll x = GCD(total, res);
        res /= x;
        total /= x;
        if (total == 1) {
            cout << res << endl;
        } else {
            cout << res << "/" << total << endl;
        }
        
    }
    return 0;
}