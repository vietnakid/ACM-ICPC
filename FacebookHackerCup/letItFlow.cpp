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

int n;
vector<string> arr(3);
vector<vvl > f;

void sovle(int x, int y, int k) {
    cout << x << " " << y << endl;
    if (x < 0 || x >= 3 || y < 0 || y >= n || f[x][y][k] != 0 || arr[x][y] == '#') {
        return;
    }
    
    if (k == 0) { // left, right
        sovle(x-1, y, 1);
        sovle(x+1, y, 1);
        f[x][y][k] = f[x-1][y][1] + f[x+1][y][1];
    } else {
        sovle(x, y-1, 0);
        sovle(x, y+1, 0);
        f[x][y][k] = f[x][y-1][0] + f[x][y+1][0];
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        cout << "Case #" << tc << ":" << endl;
        cin >> n;
        cin >> arr[0] >> arr[1] >> arr[2];
        f = vector<vvl >(3, vvl(n, vl(2, 0)));
        // sovle(2, n-1, 0);
        if (arr[0][0] != '#')
            f[0][0][1] = 1;
        FOR(j, 0, n) {
            FOR(i, 0, 3) {
                if (i >= 0 && i < 3 && j >= 0 && j < n && arr[i][j] != '#') {
                    if (j > 0) {
                        f[i][j][1] += f[i][j-1][0];
                    }
                }
                f[i][j][1] %= nMod;
            }
            FOR(i, 0, 3) {
                if (i >= 0 && i < 3 && j >= 0 && j < n && arr[i][j] != '#') {
                    if (i > 0)
                        f[i][j][0] += f[i-1][j][1];
                    if (i < 2)
                        f[i][j][0] += f[i+1][j][1];
                }
                f[i][j][1] %= nMod;
            }
            
        }
        cout << f[2][n-1][0] << endl;
    }
    return 0;
}