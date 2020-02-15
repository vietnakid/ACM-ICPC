#include <bits/stdc++.h>
#include <unistd.h>

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

int n, m;
int arr[1001][1001];
bool isFree[1001][1001];
int res = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void vietnakid() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!isFree[i][j] && arr[i][j] == 1) {
                res++;
                queue<pair<int, int>> q;
                q.push({i, j});
                isFree[i][j] = true;
                // cerr << i << " " << j << "\n";
                while (!q.empty()) {
                    pair<int, int> node = q.front();
                    q.pop();
                    int u = node.first;
                    int v = node.second;
                    for (int d = 0; d < 4; d++) {
                        int x = u + dx[d];
                        int y = v + dy[d];
                        if (x >= 0 && x < n && y >= 0 && y < m && !isFree[x][y] && arr[x][y] == 1) {
                            q.push({x, y});
                            isFree[x][y] = true;
                        }
                    }
                }
            }
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