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
    int n;
    cin >> n;
    vvi arr(n, vi(n)), f(n, vi(n, false));
    string s;
    cin >> s;
    int ii = 0;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            arr[i][j] = s[ii];
            if (s[ii] == 'I') {
                f[i][j] = true;
            }
            ii++;
        }
    }
    string res = "ICPCASIASG";
    FOR(ij, 1, res.size()) {
        char c = res[ij];
        vvi brr(n, vi(n, false));
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                if (arr[i][j] == c) {
                    FOR(ii, 0, n) {
                        FOR(jj, 0, n) {
                            if (arr[ii][jj] == res[ij-1] && (i - ii)*(i - ii) + (j - jj)*(j - jj) == 5) {
                                brr[i][j] |= f[ii][jj];
                            }
                        }
                    }
                }
            }
        }
        f = brr;
    }
    bool r = false;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (f[i][j]) {
                r = true;
                break;
            }   
        }
    }
    if (r) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}