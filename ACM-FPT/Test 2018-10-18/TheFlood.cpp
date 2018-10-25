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
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC = 0;
    while (true) {
        int n, m, mx = -1, mi, mj, mn = INF;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        TC++;
        vvi arr(n, vi(m));
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                cin >> arr[i][j];
                if (mx < arr[i][j]) {
                    mx = arr[i][j];
                    mi = i;
                    mj = j;
                }
                if (i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if (arr[i][j] < mn) {
                        mn = arr[i][j];
                    }
                }
            }
        }
        // cerr << mn << endl;
        bool isFind = false;
        for (int high = mn; high < mx && !isFind; high++) {
            // cerr << high << endl;
            vvi isFlood(n, vi(m, false));
            queue<ii> q;
            FOR(i, 0, n) {
                if (arr[i][0] <= high) {
                    isFlood[i][0] = true;
                    q.push({i, 0});
                }
                if (arr[i][m-1] <= high) {
                    isFlood[i][m-1] = true;
                    q.push({i, m-1});
                }
            }
            FOR(j, 0, m) {
                if (arr[0][j] <= high) {
                    isFlood[0][j] = true;
                    q.push({0, j});
                }
                if (arr[n-1][j] <= high) {
                    isFlood[n-1][j] = true;
                    q.push({n-1, j});
                }
            }
            while (!q.empty()) {
                ii u = q.front();
                // cerr << u.first << " -- " << u.second << endl;
                q.pop();
                FOR(i, 0, 4) {
                    int x = u.first + dx[i];
                    int y = u.second + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < m && !isFlood[x][y] && arr[x][y] <= high) {
                        // cerr << x << " " << y << endl;
                        isFlood[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
            // cerr << " ok " << endl;



        // for (int high = 5; high < 6 && !isFind; high++) {
            vvi isFree(n, vi(m, true));
            isFree[mi][mj] = false;
            q.push({mi, mj});
            while (!q.empty()) {
                ii u = q.front();
                // cerr << u.first << " -- " << u.second << endl;
                q.pop();
                FOR(i, 0, 4) {
                    int x = u.first + dx[i];
                    int y = u.second + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < m && isFree[x][y] && !isFlood[x][y]) {
                        // cerr << x << " " << y << endl;
                        isFree[x][y] = false;
                        q.push({x, y});
                    }
                }
            }
            bool check = true;
            for (int i = 0; i < n && check; i++) {
                FOR(j, 0, m) {
                    if (arr[i][j] > high && isFree[i][j]) {
                        // cerr << i << " " << j << endl;
                        // cerr << arr[i][j] << endl;
                        check = false;
                        break;
                    }       
                }
            }

            if (!check) {
                isFind = true;
                cout << "Case " << TC << ": Island splits when ocean rises " << high << " feet." << endl; 
                break;
            }
        }
        if (!isFind) {
            cout << "Case " << TC << ": Island never splits." << endl;
        }
    }
    return 0;
}