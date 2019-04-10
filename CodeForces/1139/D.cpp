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
vvii cnt(100005);
ll dp[100005];
ll rn;

ll powMod(ll a, ll n, ll mod) {
	if (n == 0 && a != 0) return 1;
    if (n == 0 && a == 0) return 0;
	if (n == 1) return a;
	ll b = powMod(a, n >> 1, mod);
	ll res = (b * b) % mod;
	if (n & 1) res = (res * a) % mod;
	return res;
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <=n; j += i) {
            cnt[j].push_back({i, n/i});
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < cnt[i].size(); j++) {
            for (int k = j+1; k < cnt[i].size(); k++) {
                if (cnt[i][k].first % cnt[i][j].first == 0) {
                    cnt[i][j].second -= cnt[i][k].second;
                }
            }
        }
    }
}

ll calDP(int u) {
    ll & res = dp[u];
    if (res != -1) return res;
    res = 0;
    for (int i = 0; i < cnt[u].size() - 1; i++) {
        ii x = cnt[u][i];
        int num = x.first;
        ll count = x.second;
        ll r = (calDP(num) * count) % nMod;
        res = (res + r) % nMod;
    }
    res = (res + n) % nMod;
    res = (res * powMod(n - cnt[u].back().second, nMod-2, nMod)) % nMod;
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    init();
    memset(dp, -1, sizeof(dp));
    rn = powMod(n, nMod-2, nMod);
    dp[1] = 0;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + calDP(i) + 1) % nMod;
        cerr << i << " " << calDP(i) << "\n";
    }
    res = (res * rn) % nMod;
    cout << res << "\n";
 	// cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}