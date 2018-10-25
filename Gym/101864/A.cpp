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

ll pow2[51];
ll x, l, n;

void init() {
    pow2[0] = 1;
    FORE(i, 1, 50) {
        pow2[i] = pow2[i-1] * 2;
    }
}

ll sovle(ll m) {
    ll sum = 0;
    ll res = 0;
    FOR(i, 0, 51) {
        sum += pow2[i];
        if (sum > m) {
            sum -= pow2[i];
            break;
        }
        if (pow2[i+1] - 1 >= x) {
            res++;
        }
    }
    ll remain = m - sum;
    if (remain * 2 - 1 >= x) {
        res++;
    }
    return res;
}

ll cal() {
    if (x % 2 == 0) {
        if (x > l)
            return x - l;
        else
            return 0;
    }
    // cerr << sovle(n) << endl;
    if (x > l) {
        return sovle(n) - sovle(x-1) + (x-l);
    } else 
        return sovle(n) - sovle(l-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    init();
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        cin >> x >> l >> n;
        cout << "Case " << tc << ": ";
        ll res = cal();
        if (res == 0) {
            cout << "0/1" << endl;
            continue;
        }
        ll divi = n-l+1;
        ll gcd = GCD(res, divi);
        cout << res/gcd << "/" << divi/gcd << endl;
        // cout << res/gcd << "/" << divi/gcd << " " << sovle(n) << endl;
    }
    return 0;
}