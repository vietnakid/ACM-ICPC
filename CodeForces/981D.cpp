#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

vl sum;
int n, k;

bool check(ll val) {
    bitset<100> dp[100];
    dp[0][0] = 1;
    FORE(j, 1, k) {
        FORE(i, j, n) {
            FORE(k, 0, i-1) {
                ll s = sum[i] - sum[k];
                if ((s & val) == val && dp[k][j-1]) {
                    dp[i][j] = 1;
                }
            }
        }
    }
    // cout << val << " " << dp[1][1] << endl;
    return dp[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> k;
    vl arr(n+1);
    sum = vl(n+1, 0);
    ll res = 0;
    FORE(i, 1, n) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    } 

    for (ll i = 60; i >= 0; i--) {
        if (check(res + (1ll << i))) {
            res += (ll)(1ll << i);
        }
    }

    cout << res << endl;
    return 0;
}