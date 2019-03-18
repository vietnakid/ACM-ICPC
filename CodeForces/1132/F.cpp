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
string s;
int dp[505][505];

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) dp[i][j] = 0;
            else if (i == j) dp[i][j] = 1;
            else dp[i][j] = INF;
        }
    }
}

void solve() {
    for (int t = 1; t < n; t++) 
    for (int i = 0; i < n; i++) {
        int j = i + t;
        if (j >= n) break;
        dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
        dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
        // for (int j = i+1; j < n; j++) {
            for (int k = i+1; k <= j; k++) {
                if (s[i] == s[k]) {
                    dp[i][j] = min(dp[i][j], dp[i+1][k] + dp[k+1][j]);
                    // cerr << i << " " << j << " " << dp[i][j] << "\n";
                }
            }
        
    }
    cout << dp[0][n-1] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    cin >> s;
    init();
    solve();
    cerr << "Time elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}