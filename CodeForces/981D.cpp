#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector< vvl > f(n+1, vvl(k+1));
    vector< vvl > ff(n+1, vvl(k+1));
    vl arr(n+1);
    vl sum(n+1, 0);
    vl sumr(n+2, 0);
    ll res = 0;
    FORE(i, 1, n) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
        f[i][1].push_back(sum[i]);
    } 
    sumr[n+1] = 0;
    FORD(i, n, 0) {
        sumr[i] = sum[i+1] + arr[i];
        ff[i][1].push_back(sum[i]);
    }

    // 2 -> n/2
    FORE(i, 2, n/2) {
        FORE(j, 2, min(i, k)) {
            FORE(ii, j-1, i-1) {
                FOR(h, 0, f[ii][j-1].size()) {
                    f[i][j].push_back(f[ii][j-1][h] & (sum[i] - sum[ii]));
                }
            }
        }
    }

    // n -> n/2
    FORE(i, 2, n/2) {
        FORE(j, 2, min(i, k)) {
            FORE(ii, j-1, i-1) {
                int reali = n - i + 1;
                int realii = n - i + 1;
                FOR(h, 0, ff[ii][j-1].size()) {
                    ff[i][j].push_back(ff[ii][j-1][h] & (sumr[i] - sumr[ii]));
                }
            }
        }
    }

    FORE(i1, 1, n/2) {
        FORE(g1, 0, min(i1, k)) {
            FORE(i2, n/2, n) {
                int g2 = k - g1 - 1;
                FOR(h1, 0, f[i1][g1].size()) {
                    FOR(h2, 0, ff[i2][g2].size()) {
                        res = max(res, f[i1][g1][h1] & ff[i2][g2][h2] & (sum[i2-1] - sum[i1]));
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}