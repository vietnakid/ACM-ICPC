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

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

vector<string> arr;
int n = 0, m = 0;
int cnt = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char xxx;

void BFS(int x, int y) {
    cnt = 0;
    queue<ii> q;
    q.push({x, y});
    arr[x][y] = xxx-1;
    while (!q.empty()) {
        cnt++;
        ii a = q.front();
        q.pop();
        x = a.first;
        y = a.second;
        // cout << x << " " << y << endl;
        FOR(i, 0, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (yy < 0) {
                yy = n-1;
            }
            if (yy >= n) {
                yy = 0;
            }
            if (xx >= 0 && xx < m && arr[xx][yy] == xxx) {
                q.push({xx, yy});
                arr[xx][yy] = xxx-1;
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        m = 0; n = 0;
        cin >> m >> n;
        if (n == 0 && m == 0) {
            break;
        }
        arr = vector<string>(m);
        FOR(i, 0, m) {
            cin >> arr[i];
        }
        int x, y;
        cin >> x >> y;
        xxx = arr[x][y];
        BFS(x, y);
        int res = 0;
        FOR(i, 0, m) {
            FOR(j, 0, n) {
                if (arr[i][j] == xxx) {
                    BFS(i, j);
                    res = max(res, cnt);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}