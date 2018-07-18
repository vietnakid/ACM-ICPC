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

int n, m;
vvi arr, d;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        int minx = INF, miny = INF, maxx = 0, maxy = 0;
        arr = vvi(2001, vi(2001, 0));
        d = vvi(2001, vi(2001, INF));
        queue<ii> q;
        cin >> n;
        if (n == 0) {
            break;
        }
        FOR(i, 0, n) {
            int x, y;
            cin >> x >> y;
            q.push({x, y});
            arr[x][y] = 1;
            d[x][y] = 0;
            minx = min(x, minx);
            maxx = max(x, maxx);
            miny = min(y, miny);
            maxy = max(y, maxy);
        }

        cin >> m;
        FOR(i, 0, m) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 2;
            minx = min(x, minx);
            maxx = max(x, maxx);
            miny = min(y, miny);
            maxy = max(y, maxy);
        }
        int res = INF;
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            FOR(i, 0, 4) {
                int x = u.first + dx[i];
                int y = u.second + dy[i];
                if (x >= minx && x <= maxx && y >= miny && y <= maxy) {
                    if (arr[x][y] == 0) {
                        arr[x][y] = 3;
                        d[x][y] = d[u.first][u.second] + 1;
                        q.push({x, y});
                    } else if (arr[x][y] == 2) {
                        d[x][y] = d[u.first][u.second] + 1;
                        res = d[x][y];
                        break;
                    }
                }
            }
            if (res != INF) {
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}