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

int n, m, k;
int arr[200005], sum[200005];
int offer[2005];
int dp[2005];

void vietnakid() {
    cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n+1);
    for (int i = 1; i <= k; i++) {
        sum[i] = sum[i-1] + arr[i];
    }
    for (int i = 0; i < m; i++) {
        int b, g; cin >> b >> g;
        if (b <= k && g > offer[b]) {
            offer[b] = g;
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = INF;
        for (int buy = 1; buy <= i; buy++) {
            int gift = offer[buy];
            dp[i] = min(dp[i], dp[i - buy] + sum[i] - sum[i-buy+gift]);
        }
    }
    cout << dp[k] << "\n";
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