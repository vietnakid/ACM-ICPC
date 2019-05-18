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
ll arr[300005];
ll x;
ll dp[300005][3];

void vietnakid() {
	cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i][0], dp[i-1][0] + arr[i]);
        dp[i][1] = max(dp[i][1], max(dp[i-1][0] + arr[i]*x, dp[i-1][1] + arr[i]*x));
        dp[i][2] = max(dp[i][2], max(dp[i-1][1] + arr[i], dp[i-1][2] + arr[i]));
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i][0]);
        res = max(res, dp[i][1]);
        res = max(res, dp[i][2]);
    }
    
    
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