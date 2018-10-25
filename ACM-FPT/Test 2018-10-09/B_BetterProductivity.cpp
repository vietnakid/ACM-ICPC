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

#define INF 1e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int n, p;
vii bad;
vi good;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> p;
    vii arr(n);
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, -y};
    }
    sort(arr.begin(), arr.end());
    FOR(i, 0, n) {
        arr[i].second = -arr[i].second;
    }

    FOR(i, 0, arr.size()) {
        bool check = false;
        FOR(j, i+1, arr.size()) {
            if (arr[i].first <= arr[j].first && arr[i].second >= arr[j].second) {
                // cerr << i << " " << j << " " << arr[i].first << " " << arr[i].second << " " << arr[j].first << " " << arr[j].second << endl;
                good.push_back({arr[i].second - arr[i].first});
                check = true;
                break;
            }
        }
        if (!check) {
            bad.push_back(arr[i]);
        }
    }
    
    sort(bad.begin(), bad.end());
    n = bad.size();

    // cerr << n << endl;
    // FOR(i, 0, n) {
    //     cerr << bad[i].first << " " << bad[i].second << endl;
    // }
    

    int g[n+1][n+1];
    memset(g, 0, sizeof(g));
    FOR(i, 0, n) {
        FORE(j, 0, i) {
            int mi = INF;
            int mx = 0;
            FORE(k, j, i) {
                mi = min(mi, bad[k].second);
                mx = max(mx, bad[k].first);
            }
            g[j+1][i+1] = mi - mx;
            if (mi - mx <= 0) {
                g[j+1][i+1] = -INF;
            }
        }
    }

    vvi f(n+1, vi(p+1, -INF));
    f[0][0] = 0;
    FORE(i, 1, n) {
        FORE(j, 1, p) {
            FOR(k, 0, i) {
                f[i][j] = max(f[i][j], f[k][j-1] + g[k+1][i]);
            }
            if (f[i][j] < 0) {
                f[i][j] = -INF;
            }
        }
    }
    // cerr << g[1][2] << endl;
    // cerr << f[8][8] << endl;

    sort(good.rbegin(), good.rend());
    vi sum(p+1, 0);
    FORE(i, 1, p) {
        if (i <= good.size()) {
            sum[i] = sum[i-1] + good[i-1];
        }
    }
    // cerr << sum[2] << endl;
    int res = f[n][p];

    FORE(i, 1, p) {
        int remain = p - i;
        res = max(res, f[n][i] + sum[remain]);
        // cerr << res << " " << f[n][i] << " " << sum[remain] << endl;
    }

    if (n == 0) {
        res = sum[p];
    }

    cout << res << endl;
    return 0;
}
