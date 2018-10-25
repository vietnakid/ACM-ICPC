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

vvl arr;
vvl fc, fr;
int n, m, q;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> m >> q;
    arr = vvl(n+2, vl(m+2, 0));
    fr = vvl(n+2, vl(m+2, 0));
    fc = vvl(n+2, vl(m+2, 0));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            scanf("%lld", &arr[i][j]);
        }
    }
    FOR(i, 0, q) {
        int x1, x2, y1, y2, val;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &val);
        fr[x1][y1] += val;
        fc[x1][y1] += val;
        arr[x1-1][y1-1] -= val;
        fr[x1][y2+1] -= val;
        fc[x2+1][y1] -= val;
    }
    FORE(i, 1, n) {
        FORE(j, 1, m) {
            fr[i][j] += fr[i][j-1];
        }
    }
    FORE(i, 1, n) {
        FORE(j, 1, m) {
            fc[i][j] += fc[i-1][j];
        }
    }
    cerr << fr[2][2] << " " << fc[2][2] << " " << arr[1][1] << endl;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            arr[i][j] += fr[i+1][j+1] + fc[i+1][j+1];
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}