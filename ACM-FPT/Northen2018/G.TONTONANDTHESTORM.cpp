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

vvi isFree;
vvl d;
queue<ii> q;

int n, m;
int xs, xd, ys, yd;

int dx[] = {-1, -1, 1, 1};
int dy[] = {1, -1, 1, -1};

bool check(int x, int y) {
    if (x <= 0 || x > n || y <= 0 || y > n) return false;
    if (!isFree[x][y]) return false;

    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &xs, &ys, &xd, &yd);
    if (xs == xd && ys == yd) {
        cout << 0 << endl;
        return 0;
    }

    isFree = vvi(n+1, vi(n+1, true));
    d = vvl(n+1, vl(n+1, INFLL));

    FOR(i, 0, m) {
        int x, y;
        scanf("%d %d", &x, &y);
        isFree[x][y] = false;
        d[x][y] = INFLL;
    }

    d[xs][ys] = 0;
    q.push({xs, ys});
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;
        // cerr << x << " " << y << endl;
        FOR(i, 0, 4) {
            FORE(j, 1, n) {
                int xx = x + dx[i]*j;
                int yy = y + dy[i]*j;
                // cerr << xx << " ---- " << yy << endl;
                if (!check(xx, yy)) {
                    break;
                }
                q.push({xx, yy});
                isFree[xx][yy] = false;
                d[xx][yy] = d[x][y] + 1;
                if (xx == xd && yy == yd) {
                    cout << d[xd][yd] << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}