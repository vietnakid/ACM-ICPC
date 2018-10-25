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
#define INFLL 1e18
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
    int n;
    while (cin >> n) {
        tc++;
        cout << "Set #" << tc << endl;
        vl c(n+1), d(n+1, INFLL);
        vi check(n+1, true);
        d[1] = 0;
        vvl arr(n+1, vl(n+1, INFLL));
        FORE(i, 1, n) {
            cin >> c[i];
        }
        
        int m;
        cin >> m;
        FOR(i, 0, m) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = pow(c[y] - c[x], 3);
        }
        FOR(ii, 0, n) {            
            FORE(i, 1, n) {
                FORE(j, 1, n) {
                    if (d[j] > d[i] + arr[i][j]) {
                        d[j] = d[i] + arr[i][j];
                    }
                }
            }
        }
        FOR(ii, 0, n) {
            FORE(i, 1, n) {
                FORE(j, 1, n) {
                    if (d[j] > d[i] + arr[i][j]) {
                        d[j] = d[i] + arr[i][j];
                        check[j] = false;
                    }
                }
            }
        }
        int q;
        cin >> q;
        FOR(i, 0, q) {
            int x;
            cin >> x;
            if (d[x] >= INF || d[x] < 3 || !check[x]) {
                cout << "?" << endl;
            } else {
                cout << d[x] << endl;
            }
        }
    }
    return 0;
}