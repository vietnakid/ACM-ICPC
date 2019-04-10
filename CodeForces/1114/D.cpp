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
int arr[5005];
int dp[5005][5005][2];

void vietnakid() {
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][0] = n;
            dp[i][j][1] = n;
        }
        dp[i][i][0] = 0;
        dp[i][i][1] = 0;
    }
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n; i++) {
            int j = i+k;
            if (j >= n) break;
            // dp[i][j][0]
            {
                int & res = dp[i][j][0];
                if (arr[i] == arr[i+1]) {
                    res = min(res, dp[i+1][j][0]);
                } else {
                    res = min(res, dp[i+1][j][0] + 1);
                }
                if (arr[i] == arr[j]) {
                    res = min(res, dp[i+1][j][1]);
                } else {
                    res = min(res, dp[i+1][j][1] + 1);
                }
            }
            // dp[i][j][1]
            {
                int & res = dp[i][j][1];
                if (arr[j] == arr[j-1]) {
                    res = min(res, dp[i][j-1][1]);
                } else {
                    res = min(res, dp[i][j-1][1] + 1);
                }
                if (arr[i] == arr[j]) {
                    res = min(res, dp[i][j-1][0]);
                } else {
                    res = min(res, dp[i][j-1][0] + 1);
                }
            }
            // cerr << "i = " << i << " | j = " << j << " || " << dp[i][j][0] << " " << dp[i][j][1] << "\n";
        }
    }
    cout << min(dp[0][n-1][0], dp[0][n-1][1]) << "\n";
    
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