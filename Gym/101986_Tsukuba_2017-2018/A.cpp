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

int l, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> l >> k;
    ll f[101][2];
    memset(f, 0, sizeof(f));
    f[0][0] = 1;

    for (int i = 1; i <= l; i++) {
        for (int j = 0; j < 2; j++) {
            f[i][j] += f[i-1][1-j];
            if (j == 1 && i - k >= 0) {
                f[i][j] += f[i-k][1-j];
            }
        }
    }

    ll res = 0;
    for (int i = 0; i<= l; i++) {
        res += f[i][1];
        // cerr << i << " " << f[i][0] << " " << f[i][1] << endl;
    }
    cout << res << endl;
    return 0;
}