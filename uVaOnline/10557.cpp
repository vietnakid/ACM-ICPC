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
    while (true) {
        int n;
        cin >> n;
        if (n == -1) {
            break;
        }
        vvl arr(n+1);
        vl p(n+1);
        vl d(n+1, -INF);
        vi check(n+1, false);
        bool res = false;
        d[1] = 100;

        FORE(i, 1, n) {
            cin >> p[i];
            int m;
            cin >> m;
            FOR(j, 0, m) {
                ll x;
                cin >> x;
                arr[i].push_back(x);
            }
        }

        FOR(ii, 0, n-1) {
            FORE(u, 1, n) {
                FOR(i, 0, arr[u].size()) {
                    int v = arr[u][i];
                    if (d[v] < d[u] + p[v] && d[u] + p[v] > 0) {
                        d[v] = d[u] + p[v];
                    }
                }
            }
        }
        
        FOR(ii, 0, n) {
            FORE(u, 1, n) {
                FOR(i, 0, arr[u].size()) {
                    int v = arr[u][i];
                    if (d[v] < d[u] + p[v] && d[u] + p[v] > 0) {
                        d[v] = d[u] + p[v];
                        d[v] = INFLL;
                    }
                }
            }
        }

        FOR(ii, 0, n-1) {
            FORE(u, 1, n) {
                FOR(i, 0, arr[u].size()) {
                    int v = arr[u][i];
                    if (d[v] < d[u] + p[v] && d[u] + p[v] > 0) {
                        d[v] = d[u] + p[v];
                    }
                }
            }
        }

        if (d[n] > 0) {
            res = true;
        }
        if (res) {
            cout << "winnable" << endl;
        } else {
            cout << "hopeless" << endl;
        }
    }
    return 0;
}