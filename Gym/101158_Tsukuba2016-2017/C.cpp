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

#define FOR(i, a, b) \
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m;
vvi f, g, arm;
vii arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m;
    arr.resize(m);
    FOR(i, 0, m) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr.begin(), arr.end());

    arm.resize(n+2);

    f.resize(n+2);
    g.resize(n+2);

    FOR(i, 0, m) {
        arm[arr[i].first].push_back(arr[i].second);
    }

    arm[0].push_back(0);
    arm[n+1].push_back(0);

    f[0].push_back(0);

    FORE(i, 1, n) {
        int j = -1;
        FOR(k, 0, arm[i].size()) {
            f[i].push_back(1);
            while (j + 1 < arm[i-1].size() && arm[i-1][j+1] <= arm[i][k]) {
                j++;
            }
            if (j != -1) {
                f[i][k] += f[i-1][j];
            }
            // cerr << i << " " << k << " " << f[i][k] << endl;
        }
    }

    g[n].push_back(0);
    
    FORD(i, n-1, 1) {
        int j = -1;
        FOR(k, 0, arm[i].size()) {
            g[i].push_back(1);
            while (j + 1 < arm[i+1].size() && arm[i+1][j+1] <= arm[i][k]) {
                j++;
            }
            if (j != -1) {
                g[i][k] += g[i+1][j];
            }

            // cerr << i << " " << k << " " << g[i][k] << endl;
        }
    }

    FORE(i, 1, n) {
        // cerr << " ok " << i << " " << g[i].size() << endl;
        // cerr << f[i-1][f[i-1].size() - 1] << " " << g[i][g[i].size() - 1] << endl;
        int res = 1;
        if (f[i-1].size() > 0) {
            res += f[i-1][f[i-1].size() - 1];
        }
        if (g[i].size() > 0) {
            res += g[i][g[i].size() - 1];
        }
        cout << res << " ";
    }
    return 0;
}