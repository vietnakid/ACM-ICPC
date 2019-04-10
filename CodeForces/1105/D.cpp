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

int n, m, k;
vector<queue<ii> > vq(10);
vector<string> arr(1005);
vi s(10);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isEmptyAllQueue() {
    for (int i = 1; i <= k; i++) {
        if (!vq[i].empty()) return false;
    }
    return true;
}

bool inRange(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

void vietnakid() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
        s[i] = min(s[i], n+m-1);
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != '.' && arr[i][j] != '#') {
                int u = arr[i][j] - '0';
                vq[u].push({i, j});
            }
        }
    }

    while (!isEmptyAllQueue()) {
        for (int i = 1; i <= k; i++) {
            // cerr << i << " size =  " << vq[i].size() << "\n";
            for (int j = 0; j < s[i]; j++) {
                queue<ii> tmp;
                if (vq[i].empty()) break;
                while (!vq[i].empty()) {
                    ii u = vq[i].front(); vq[i].pop();
                    // cerr << "u = " << u.first << " " << u.second << "\n";
                    for (int ii = 0; ii < 4; ii++) {
                        int x = u.first+dx[ii]; int y = u.second+dy[ii];
                        if (inRange(x, y) && arr[x][y] == '.') {
                            tmp.push({x, y});
                            arr[x][y] = i + '0';
                        }
                    }
                }
                vq[i] = tmp;
            }
        }
    }
    int res[10];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != '.' && arr[i][j] != '#') {
                int u = arr[i][j] - '0';
                res[u]++;
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << res[i] << " ";
    }
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