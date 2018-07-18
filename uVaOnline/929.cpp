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

#define INF 1e9+7
#define INFLL 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m;
vvi arr;
vvi dist;
priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> m;
        arr = vvi(n, vi(m, 0));
        dist = vvi(n, vi(m, INF));
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                cin >> arr[i][j];
            }
        }
        dist[0][0] = arr[0][0];
        pq.push({arr[0][0], {0, 0}});
        while (!pq.empty()) {
            pair<int, ii> node = pq.top();
            pq.pop();
            ii u = node.second;
            int d = node.first;
            if (d > dist[u.first][u.second]) {
                continue;
            } else {
                FOR(i, 0, 4) {
                    int x = u.first + dx[i];
                    int y = u.second + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] > arr[x][y] + d) {
                        dist[x][y] = arr[x][y] + d;
                        pq.push({dist[x][y], {x, y}});
                    }
                }
            }
        }
        cout << dist[n-1][m-1] << endl;
    }
    return 0;
}