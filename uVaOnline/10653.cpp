#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int m, n, k;
vvi arr, isFree, d;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break;
        }
        arr = vvi(m, vi(n, INF));
        isFree = vvi(m, vi(n, true));

        cin >> k;
        FOR(i, 0, k) {
            int x, h;
            cin >> x >> h;
            FOR(j, 0, h) {
                int y;
                cin >> y;
                isFree[x][y] = false;
            }
        }

        ii src, dst;
        cin >> src.first >> src.second;
        cin >> dst.first >> dst.second;

        isFree[src.first][src.second] = false;
        arr[src.first][src.second] = 0;
        queue<ii> q;
        q.push(src);
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            FOR(i, 0, 4) {
                int x = u.first + dx[i];
                int y = u.second + dy[i];
                if (x >= 0 && x < m & y >= 0 && y < n) {
                    if (isFree[x][y]) {
                        arr[x][y] = arr[u.first][u.second] + 1;
                        isFree[x][y] = false;
                        q.push({x, y});
                    }
                }
            }
        }
        cout << arr[dst.first][dst.second] << endl;
    }
    return 0;
}