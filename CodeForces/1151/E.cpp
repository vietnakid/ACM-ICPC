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

int n;
int a[100005];

void vietnakid() {
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll res = 1LL * n * n * (n + 1) / 2;
    for (ll i = 0; i < n - 1; i++) {
        ll l = min(a[i], a[i + 1]), r = max(a[i], a[i + 1]);
        res -= 1LL * l * (n - r + 1);
    }
    for (ll i = 0; i < n; i++)
        res -= 1LL * (a[i] - 1) * a[i] / 2 + 1ll * (n - a[i]) * (n - a[i] + 1) / 2;
    cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}