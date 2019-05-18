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

const int HOR = 0;
const int VER = 1;

int n, m, res;
vector<string> arr;

void move(int x, int y, int dir, vector<string> & arr ) {
    if (dir == HOR) {
        for (int i = y; i >= 0; i--) {
            if (arr[x][i] == 'a') break;
            arr[x][i] = 'a';
        }
        for (int i = y+1; i < m; i++) {
            if (arr[x][i] == 'a') break;
            arr[x][i] = 'a';
        }
    } else {
        for (int i = x; i >= 0; i--) {
            if (arr[i][y] == 'a') break;
            arr[i][y] = 'a';
        }
        for (int i = x+1; i < n; i++) {
            if (arr[i][y] == 'a') break;
            arr[i][y] = 'a';
        }
    }
}

int AlphaBeta(int x, int y, int dir, vector<string> arr) {
    int res = 1;
    move(x, y, dir, arr);
    vi ver(15, true), hor(15, true);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == '#') {
                ver[j] = false;
                hor[i] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < 2; dir++) {
                if (dir == HOR) {
                    if (hor[i] && arr[i][j] != 'a') {
                        res = min(res, 1-AlphaBeta(i, j, dir, arr));
                    }
                }
                else {
                    if (ver[j] && arr[i][j] != 'a') {
                        res = min(res, 1-AlphaBeta(i, j, dir, arr));
                    }
                }
            }
            
        }
    }
    return res;
}

void solve(int tc) {
    res = 0;

    vi ver(15, true), hor(15, true);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == '#') {
                ver[j] = false;
                hor[i] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < 2; dir++) {
                if (dir == HOR) {
                    if (hor[i] && arr[i][j] != 'a') {
                        // cerr << i << " --- " << j << " " << dir << "\n";
                        res += AlphaBeta(i, j, dir, arr);
                    }
                }
                else {
                    if (ver[j] && arr[i][j] != 'a') {
                        // cerr << i << " --- " << j << " " << dir << "\n";
                        res += AlphaBeta(i, j, dir, arr);
                    }
                }
            }
            
        }
    }
    cout << "Case #" << tc << ": " << res << "\n";
}

void vietnakid() {
    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> n >> m;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(tc);
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