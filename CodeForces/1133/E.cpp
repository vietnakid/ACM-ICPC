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

int n, k;
vi arr;
int dp[5005][5005];

int calDP(int n, int k) {
    if (n <= 0 || k <= 0) return 0;
    int & res = dp[n][k];
    if (res != -1) return res;
    int pos = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), arr[n] - 5));
    // cerr << n << " " << k << " " << pos << "\n";
    res = max(res, calDP(pos-1, k-1) + n-pos+1);
    res = max(res, calDP(n-1, k));
    return res;
}

void vietnakid() {
    cin >> n >> k;
    arr.resize(n+1);
    arr[0] = -INF;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    cout << calDP(n, k) << "\n";
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