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

int m, n, dir;
vector< vvi > arr, isFree;
vvi obstacle;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

pair<ii, int> process(pair<ii, int> u, int step) {
    pair<ii, int> res = u;
    if (step == 0) {
        res.second = (res.second + 1) % 4;
    } else if (step == 1) {
        res.second--;
        if (res.second == -1) {
            res.second = 3;
        }
    } else {
        res.first.first += dx[res.second] * (step - 1);
        res.first.second += dy[res.second] * (step - 1);
    }
    return res;
}

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

        arr = vector< vvi >(m+1, vvi(n+1, vi(4, INF)));
        isFree = vector< vvi >(m+1, vvi(n+1, vi(4, true)));
        obstacle = vvi(m+1, vi(n+1, false));

        FOR(i, 0, m) {
            FOR(j, 0, n) {
                int x;
                cin >> x;
                if (x == 1) {
                    FOR(k, 0, 4) {
                        isFree[i][j][k] = false;
                        isFree[i][j+1][k] = false;
                        isFree[i+1][j][k] = false;
                        isFree[i+1][j+1][k] = false;
                    }
                    obstacle[i][j] = true;
                    obstacle[i][j+1] = true;
                    obstacle[i+1][j] = true;
                    obstacle[i+1][j+1] = true;
                }
            }
        }

        ii src, dst;
        cin >> src.first >> src.second;
        cin >> dst.first >> dst.second;
        string direction;
        cin >> direction;
        if (direction == "north") {
            dir = 0;
        } else if (direction == "west") {
            dir = 1;
        } else if (direction == "south") {
            dir = 2;
        } else {
            dir = 3;
        }
        
        arr[src.first][src.second][dir] = 0;
        queue<pair<ii, int> > q;
        if (src.first > 0 && src.first < m && src.second > 0 && src.second < n && isFree[src.first][src.second][dir]) {
            q.push({src, dir});
        }
        while (!q.empty()) {
            pair<ii, int> u = q.front();
            q.pop();
            // cerr << u.first.first << " " << u.first.second << " " << u.second << " " << arr[u.first.first][u.first.second][u.second] << endl;
            if (u.first.first == dst.first && u.first.second == dst.second) {
                break;
            }
            FOR(i, 0, 5) {
                pair<ii, int> v = process(u, i);
                int x = v.first.first;
                int y = v.first.second;
                int d = v.second;
                // if (x >= 0 && x <= m && y >= 0 && y <= n && isFree[x][y][d]) {
                if (x > 0 && x < m && y > 0 && y < n && isFree[x][y][d]) {
                    if (arr[x][y][d] == INF) {
                        arr[x][y][d] = arr[u.first.first][u.first.second][u.second] + 1;
                        q.push({{x, y}, d});
                        isFree[x][y][d] = false;
                    }
                } else if (x > 0 && x < m && y > 0 && y < n && obstacle[x][y]) { 
                    break;
                }
            }
        }
        int res = INF;
        FOR (i, 0, 4) {
            res = min(res, arr[dst.first][dst.second][i]);
        }
        if (res == INF) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}