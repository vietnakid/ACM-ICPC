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
    int TC;
    cin >> TC;
    FORE(tc, 1, TC) {
        cout << "Case #" << tc << ": ";
        int n, k;
        cin >> n >> k;
        int K = k;
        vvi arr(n+1, vi(n+1, 0));
        arr[1][n] = k;
        arr[n][1] = k;
        int sum = 0;
        int edge = 1;
        if (k > 2 && n > 2) {
            FOR(i, 1, n) {
                k--;
                sum += k;
                edge++;
                if (k == 1) {
                    arr[i][n] = k;
                    arr[n][i] = k;
                    break;
                } else {
                    arr[i][i+1] = k;
                    arr[i+1][i] = k;
                }
            }
        }
        if (sum == 0) {
            sum = K;
        }
        cout << sum - K << endl;
        cout << edge << endl;
        FORE(i, 1, n) {
            FORE(j, i+1, n) {
                if (arr[i][j] != 0) {
                    cout << i << " " << j << " " << arr[i][j] << endl;
                }
            }
        }

    }
    return 0;
}