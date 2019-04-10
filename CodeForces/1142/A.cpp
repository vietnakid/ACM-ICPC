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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll n, k, a, b;
ll s, t;
ll x = INFLL, y = -1;

ll calPos(ll x) {
    x = (x + n*k) % (n*k);
    if (x == 0) x = n*k;

    return x;
}

void cal() {
    if (t < s) t += n*k;
    ll l = t - s;
    if (l == 0) l = n*k;
    // cerr << s << " " << t << " " << l << "\n";
    ll step = (n*k) / GCD(l, n*k);
    x = min(x, step);
    y = max(y , step);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
 	cin >> n >> k >> a >> b;
    
    s = calPos(a + 1);
    for (int i = 0; i <= n; i++) {
        t = calPos((i*k) + b + 1);
        cal();
        t = calPos((i*k) + 1 - b);
        cal();
    }
    s = calPos(1 - a);
    for (int i = 0; i <= n; i++) {
        t = calPos((i*k) + b + 1);
        cal();
        t = calPos((i*k) + 1 - b);
        cal();
    }
    cout << x << " " << y << "\n";
    return 0;
}