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
    while (cin >> n) {
        double arr[21][20][20];
        int trace[21][20][20];
        memset(arr, 0, sizeof(arr));
        // vector< vector<double> > arr(n, vector<double>(n));
        // vvi trace(n, vi(n));
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                trace[0][i][j] = i;
                if (i == j) {
                    arr[0][i][j] = 1.0;
                } else {
                    cin >> arr[0][i][j];
                }
            }
        }
        FORE(t, 1, n) {
        FOR(k, 0, n) {
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                FOR(tt, 0, t) {
                    if (arr[t][i][j] < arr[tt][i][k] * arr[t-tt-1][k][j]) {
                        arr[t][i][j] = arr[tt][i][k] * arr[t-tt-1][k][j];
                        trace[t][i][j] = trace[t-tt-1][k][j];
                    }
                }
                }
            }
        }
        }
        bool isFound = false;
        FORE(t, 1, n) {
            if (isFound) break;
            FOR(i, 0, n) {
                if (isFound) break;
                if (arr[t][i][i] > 1.01) {
                    isFound = true;
                    vi tmp;
                    tmp.push_back(i);
                    int j = trace[t][i][i];
                    while (t != 0) {
                        // cerr << i << " " << j << endl;
                        tmp.push_back(j);
                        t--;
                        j = trace[t][i][j];
                    }
                    tmp.push_back(i);
                    reverse(tmp.begin(), tmp.end());
                    FOR(i, 0, tmp.size()) {
                        cout << tmp[i] + 1;
                        if (i != tmp.size() - 1) {
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
        if (!isFound) {
            cout << "no arbitrage sequence exists" << endl;
        }
        
    }
    return 0;
}