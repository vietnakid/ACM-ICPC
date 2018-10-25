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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int tc = 0;
    while (true) {
        tc++;
        map<int, int> mp;
        vvi arr(101, vi(101, INF));
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            break;
        }
        while (true) {
            arr[x][y] = 1;
            cin >> x >> y;
            if (x == 0 && y == 0) {
                break;
            }
        }
        FORE(k, 1, 100) {
            FORE(i, 1, 100) {
                FORE(j, 1, 100) {
                    if (i != j) {
                        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    }
                }
            }
        }
        double res = 0;
        int cnt = 0;
        FORE(i, 1, 100) {
            FORE(j, 1, 100) {
                if (arr[i][j] != INF) {
                    res += arr[i][j];
                    cnt++;
                }
            }
        }
        res /= (double)(cnt);
        printf("Case %d: average length between pages = %.3f clicks\n", tc, res);
    }
    return 0;
}