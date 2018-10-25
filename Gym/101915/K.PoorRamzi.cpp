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

vi sum;
vvi f;
int n;

int calSum(int i, int j) {
    return sum[j] - sum[i-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    while (TC--) {
        string arr;
        cin >> arr;
        n = arr.size();
        sum.resize(n+1);
        sum[0] = 0;
        FORE(i, 1, n) {
            sum[i] = sum[i-1] + (arr[i-1] - '0');
        }
        f = vvi(n+1, vi(n+1, 0));
        FORE(i, 0, n)
            FORE(j, i, n) {
                f[i][j] = 1;
            }
        FOR(leng, 1, n) {
            FORE(i, 1, n) {
                int j = i + leng;
                if (j > n) break;
                FOR(k, i, j) {
                    if (calSum(i, k) == calSum(k+1, j)) {
                        f[i][j]++;
                    }
                }
                FOR(k, i+1, j) {
                    FOR(l, k, j) {
                        if (calSum(i, k-1) == calSum(l+1, j)) {
                            f[i][j] = (f[i][j] + f[k][l]) % nMod;
                        }
                    }
                }
            }
        }
        cout << f[1][n] << endl;
    }
    return 0;
}