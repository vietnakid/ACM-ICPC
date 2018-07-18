#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int n, m;
vvi arr;
vi permu;
ll res;
vi resPermu;

void doGroup1() {
    permu = vi(n, 0);
        res = INF;
        FOR(i, 0, n) {
            permu[i] = i;
        }
        do {
            int cnt = 0;
            vi pos(n, 0);
            FOR(i, 0, n) {
                pos[permu[i]] = i;
            }
            FOR(i, 0, n) {
                FOR(j, 0, arr[i].size()) {
                    int v = arr[i][j];
                    cnt += abs(pos[v] - pos[i]);
                }
            }
            if (cnt/2 < res) {
                res = cnt/2;
                resPermu = permu;
            }
        } while (next_permutation(permu.begin(), permu.end()));
        cout << res << endl;
        FOR(i, 0, n) {
            cout << resPermu[i] << " ";
        }
        cout << endl;
}

void doGroup2() {

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        cout << "Case #" << tc << endl;
        cin >> n >> m;
        arr = vvi(n);
        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        if (n <= 9) {
            doGroup1();
        } else {
            doGroup2();
        }
    }
    return 0;
}