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
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1e9+7
#define INFLL 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        vvii arr(n);
        FOR(i, 0, m) {
            int x, y, c;
            cin >> x >> y >> c;
            arr[x].push_back({y, c});
        }
        vi d(n, INF);
        d[0] = 0;
        FOR(ii, 0, n-1) {
            FOR(i, 0, n) {
                FOR(j, 0, arr[i].size()) {
                    int u = arr[i][j].first;
                    int c = arr[i][j].second;
                    if (d[u] > d[i] + c) {
                        d[u] = d[i] + c;
                    }
                }
            }
        }
        bool check = false;
        FOR(i, 0, n) {
            FOR(j, 0, arr[i].size()) {
                int u = arr[i][j].first;
                int c = arr[i][j].second;
                if (d[u] > d[i] + c) {
                    check = true;
                }
            }
        }
        if (check) {
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }
    }
    return 0;
}