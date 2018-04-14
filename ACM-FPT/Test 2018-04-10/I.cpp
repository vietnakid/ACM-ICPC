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
typedef set<int> si;

#define FOR(i, a, b) \
for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
for (int i = (a); i <= (b); i++)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int dx[] = {0, 0, -1 , -1 , -1, 1, 1, 1};
int dy[] = {-1, 1, -1, 0, 1, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        vvi arr(n);
        FOR(i, 0, n) arr[i] = vi(m, 0);
        FOR(i, 0, n)
        FOR(j, 0, m) cin >> arr[i][j];
        set<int> res;
        FOR(i, 0, n)
        FOR(j, 0, m) {
            if (arr[i][j] != -1)
                FOR(ii, 0, 8) {
                    int x = i + dx[ii];
                    int y = j + dy[ii];
                    if (x >= 0 && y >= 0 && x < n && y < m) {
                        if (arr[i][j] == arr[x][y]) {
                            res.insert(arr[i][j]);
                        }
                    }
                }
        }
        cout << res.size() << endl;
    }
    return 0;
}
