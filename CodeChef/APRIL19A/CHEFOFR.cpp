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

int n, q, k, m;
uint64_t a[100005], arr[55], sum[55];

bool check(uint64_t state) {
    bitset<60> dp[60];
    dp[0][0] = true;
    for (int i = 1; i <= m; i++) {
        for (int g = 1; g <= k; g++) {
            for (int j = 1; j <= i; j++) {
                uint64_t s = sum[i] - sum[j-1];
                if ((s & state) == state) {
                    dp[i][g] = dp[i][g] | dp[j-1][g-1];
                } else {
                    dp[i][g] = dp[i][g] | false;
                }
            }
        }
    }
    return dp[m][k];
}

void solve() {
    if (m < k) {
        cout << 0 << "\n";
        return;
    }
    uint64_t res = 0;
    for (int i = 60; i >= 0; i--) {
        if (check(res | ((uint64_t)1 << i))) {
            res |= (uint64_t)1 << i;
        }
    }
    cout << res << "\n";
}

void vietnakid() {
	cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    for (int qq = 0; qq < q; qq++) {
        cin >> k;
        m = 0;
        for (int i = 0; i < n; i++) {
            uint64_t t; cin >> t;
            if (t > 0) {
                m++;
                arr[m] = a[i] * t;
                sum[m] = sum[m-1] + arr[m];
            }
        }
        solve();
    }
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