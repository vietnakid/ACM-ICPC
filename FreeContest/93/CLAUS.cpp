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
double s;
vector<pair<ii, int> > arr(15);
int res = 0;
vi resvi;
double dp[33768][15];
bool isVisted[33768][15];
double cost[15][15];
int trace[33768][15];

double calDistance(pair<ii, int> a, pair<ii, int> b) {
    ii x = a.first;
    ii y = b.first;
    return sqrt((x.first - y.first)*(x.first - y.first) + (x.second - y.second)*(x.second - y.second));
}

double calDP(int state, int u) {
    if (isVisted[state][u]) {
        return dp[state][u];
    }
    // cerr << state << " " << u << " " << dp[state][u] << endl;
    isVisted[state][u] = true;
    int _state = state ^ (1 << u);
    for (int v = 0; v < n; v++) {
        if (_state & (1 << v)) {
            // cerr << _state << " " << v << endl;
            double costToV = calDP(_state, v) + cost[u][v];
            if (dp[state][u] > costToV) {
                trace[state][u] = v;
                dp[state][u] = costToV;
            }
        }
    }
    // cerr << endl;
    
    return dp[state][u];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = calDistance(arr[i], arr[j]);
        }
    }
    memset(isVisted, false, sizeof(isVisted));
    memset(trace, -1, sizeof(trace));
    for (int state = 0; state < (1<<n); state++) {
        for (int i = 0; i < n; i++) {
            dp[state][i] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        isVisted[1 << i][i] = true;
        dp[1 << i][i] = calDistance({{0, 0}, 0}, arr[i]);
        trace[1<<i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        calDP((1 << n) - 1, i);
    }
    // cerr << dp[3][1] << endl;

    for (int i = 0; i < (1 << n); i++) {
        double cost = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cost += arr[j].second;
                cnt++;
            }
        }
        double minn = INF;
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                double finalCost = dp[i][j] + calDistance({{0, 0}, 0}, arr[j]);
                if (minn > finalCost) {
                    minn = finalCost;
                    u = j;
                    // cerr << u << " --- " << finalCost << endl;
                }
            }
        }
        if ((cost + minn) - s <= esp) {
            if (cnt > res) {
                // cerr << cnt << " " << cost + minn << endl;
                resvi.resize(0);
                res = cnt;
                int state = i;
                // cerr << state << " " << u << " - " << cnt << " " << (cost + minn) << endl;
                resvi.push_back(u+1);
                while (__builtin_popcount(state) > 1) {
                    int v = trace[state][u];
                    state = state ^ (1 << u);
                    resvi.push_back(v+1);
                    u = v;
                    // cerr << state << endl;
                }
            }
        }
    }
    cout << res << endl;
    reverse(resvi.begin(), resvi.end());
    for (auto x : resvi) {
        cout << x << " ";
    }
    cout << endl;
    // cout << endl;
    // cerr << dp[3][0] << " " << trace[3][0] << endl;
    return 0;
}