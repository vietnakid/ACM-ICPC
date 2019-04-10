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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int arr[5005][5005];
int n, k;
vvi minA(5005, vi(5005, INF)), minB(5005, vi(5005, INF)), isFree(5005, vi(5005, true));
queue<ii> q;

int dxA[] = {1, 1, 0};
int dyA[] = {1, 0, 1};
int dxB[] = {1, 1, 0};
int dyB[] = {-1, 0, -1};

bool isInRange(int u, int v) {
    if (u < 1 || v < 1 || u > n || v > n) return false;
    return true;
}

void BFSA() {
    while (!q.empty()) {
        ii node = q.front(); q.pop();
        int u = node.first; int v = node.second;
        for (int i = 0; i < 3; i++) {
            int x = u + dxA[i];
            int y = v + dyA[i];
            if (isInRange(x, y) && isFree[x][y] && arr[x][y] == 0) {
                q.push({x, y});
                minA[x][y] = minA[u][v] + 1;
                isFree[x][y] = false;
            }
        }
    }
}

void BFSB() {
    while (!q.empty()) {
        ii node = q.front(); q.pop();
        int u = node.first; int v = node.second;
        for (int i = 0; i < 3; i++) {
            int x = u + dxB[i];
            int y = v + dyB[i];
            if (isInRange(x, y) && isFree[x][y] && arr[x][y] == 0) {
                q.push({x, y});
                minB[x][y] = minB[u][v] + 1;
                isFree[x][y] = false;
            }
        }
    }
}

void vietnakid() {
	cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        arr[u][v] = 1;
    }
    q.push({1, 1});
    isFree[1][1] = false;
    minA[1][1] = 0;
    BFSA();

    q.push({1, n});
    isFree = vvi(5005, vi(5005, true));
    isFree[1][n] = false;
    minB[1][n] = 0;
    BFSB();


    int res = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (arr[i][j] == 0) {
                res = min(res, max(minA[i][j], minB[i][j]));
                // cerr << i << " " << j << " " << res << " || " << minA[i][j] << " " << minB[i][j] << "\n";
            }
                
    }
    cout << res << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}