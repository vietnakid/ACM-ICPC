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

long double f[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    long double p;
    while (cin >> n >> p) {
        if (n == 0) break;
        memset(f, 0, sizeof(f));

        FORE(i, 0, n) {
            f[0][i] = 1;
        }
        
        FORE(i, 1, n) {
            f[i][0] = f[i-1][0] * (1-p);
            FOR(j, 1, i-1) {
                f[i][j] = f[i-1][j];
                f[i][j] -= f[i-j-2][j]*(1-p)*pow(p, j+1);
            }
            if (i != 1)
                f[i][i-1] = 1 - pow(p, i);
            FORE(j, i, n) {
                f[i][j] = 1;
            }
        }
        double res = 0;
        FORE(j, 1, n) {
            res += j * (f[n][j] - f[n][j-1]);
        }
        printf("%.10lf\n", res); 
    }
    return 0;
}