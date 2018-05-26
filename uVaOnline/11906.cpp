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

vvi cnt, arr;

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};
int r, c, m, n;

void DFS(int x, int y) {
    arr[x][y] = false;
    set<ii> tox;
    FOR(i, 0, 4) {
        int xx = x + dx[i] * n;
        int yy = y + dy[i] * m;
        if (xx >= 0 && xx < r && yy >= 0 && yy < c)
            tox.insert({xx, yy});
        xx = x + dx[i] * m;
        yy = y + dy[i] * n;
        if (xx >= 0 && xx < r && yy >= 0 && yy < c) 
            tox.insert({xx, yy});
    }
    for(ii x : tox) {
        int xx = x.first;
        int yy = x.second;
        cnt[xx][yy]++;
        if (arr[xx][yy]) {
            DFS(xx, yy);
        }
    }
    
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        cin >> r >> c >> m >> n;
        arr = vvi(r, vi(c, true));
        cnt = vvi(r, vi(c, 0));
        int k;
        cin >> k;
        vvi dontcount(r, vi(c, true));
        cnt[0][0] = 2;
        FOR(j, 0, k) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = false;
            dontcount[x][y] = false;
        }
        DFS(0, 0);
        int res[] = {0, 0};
        FOR(i, 0, r) {
            FOR(j, 0, c) {
                if (cnt[i][j] > 0 && dontcount[i][j]) {
                    res[cnt[i][j] % 2]++;
                }
            }
        }
        cout << "Case " << tc << ": " << res[0] << " " << res[1] << endl;
    }
    
    return 0;
}