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

int n, m;
int arr[10005];
int dp[10005][505][2];

int calDP(int pos, int stama, bool isRun) {
    int & res = dp[pos][stama][isRun];
    if (res != -1) {
        return res;
    }
    res = -INF;
    if (isRun) {
        if (stama == m) res = -INF;
        else {
            res = calDP(pos-1, stama+1, true) + arr[pos];
            if (stama == m-1) {
                res = max(res, calDP(pos-1,m, false) + arr[pos]);
            }
        }
    } else {
        if (stama > 0) {
            res = max(res, calDP(pos-1, stama-1, false));
            res = max(res, calDP(pos-1, stama-1, true));
        }
        if (stama == m) {
            res = max(res, calDP(pos-1, m, false));
        }
    }
    // cerr << pos << " " << stama << " " << isRun << " " << res << endl;
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][m][false] = 0;
    for (int i = 0; i<m; i++) dp[0][i][0] = dp[0][i][1] = -INF;
    cout << calDP(n, m, false) << endl;
    return 0;
}