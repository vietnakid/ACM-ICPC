#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, ll> ii;
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
ll w[300005];
vvii arr(300005);
vl dp(300005);
ll res = -INF;

void calDP(int u, int father) {
    dp[u] = -INF;
    for (auto x : arr[u]) {
        int v = x.first;
        ll c = x.second;
        if (v != father) {
            calDP(v, u);
            res = max(res, dp[u] + dp[v] - c);
            dp[u] = max(dp[u], dp[v] - c + w[u]);
        }
    }
    dp[u] = max(dp[u], w[u]);
    res = max(res, dp[u]);
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        arr[u].push_back({v, c});
        arr[v].push_back({u, c});
    }
}

void vietnakid() {
    input();
    calDP(1, 0);
    cout << res << "\n";
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