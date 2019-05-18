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

int n, l, r;
ll cnt[3];
ll dp[200005][3];

int calRemain(int x, int remain) {
    int res = x / 3;
    if (remain == 1) {
        res += (x%3) != 0;
    } else if (remain == 2) {
        res += (x%3) == 2;
    }
    return res;
}

void init() {
    for (int i = 0; i < 3; i++) {
        cnt[i] = calRemain(r, i) - calRemain(l-1, i);
        // cerr << cnt[i] << "\n";
    }
}

void vietnakid() {
    cin >> n >> l >> r;
    init();
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i-1][0]*cnt[0] + dp[i-1][1]*cnt[2] + dp[i-1][2]*cnt[1]) % nMod;
        dp[i][1] = (dp[i-1][0]*cnt[1] + dp[i-1][1]*cnt[0] + dp[i-1][2]*cnt[2]) % nMod;
        dp[i][2] = (dp[i-1][0]*cnt[2] + dp[i-1][1]*cnt[1] + dp[i-1][2]*cnt[0]) % nMod;
    }
    cout << dp[n][0] << "\n";
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