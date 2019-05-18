#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
int r1, c1, r2, c2;
string s[55];
queue<ii> q;
vii arr, arr1, arr2;
bool isFree[55][55];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
ll res = INFLL;

bool inRange(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

void BFS() {
    while (!q.empty()) {
        ii u = q.front(); q.pop();
        int x = u.first, y = u.second;
        arr.push_back({x, y});
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (inRange(xx, yy) && isFree[xx][yy] == false && s[xx][yy] == '0') {
                q.push({xx, yy});
                isFree[xx][yy] = true;
            }
        }
    }
}

void vietnakid() {
    cin >> n;
    cin >> r1 >> c1; r1--; c1--;
    cin >> r2 >> c2; r2--; c2--;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    q.push({r1, c1});
    isFree[r1][c1] = true;
    BFS();
    arr1 = arr;
    arr.clear(); arr.resize(0);
    q.push({r2, c2});
    isFree[r2][c2] = true;
    BFS();
    arr2 = arr;

    for (auto x1 : arr1) {
        // cerr << x1.first << " " << x1.second << "\n";
        for (auto x2 : arr2) {
            res = min(res, (x1.first-x2.first)*(x1.first-x2.first) + (x1.second-x2.second)*(x1.second-x2.second));
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