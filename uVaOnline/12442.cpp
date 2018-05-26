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

vi arr;
vi cnt, isFree, isDone;
int f;

void DFS(int u) {
    isFree[u] = false;
    if (isFree[arr[u]]) {
        DFS(arr[u]);
    } else {
        if (!isDone[arr[u]])
            f = arr[u];
    }
    cnt[u] += cnt[arr[u]] + 1;
    isDone[u] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1 ,TC) {
        int res = 0, resc = INF;
        int n; cin >> n;
        arr = vi(n+1, 0);
        cnt = vi(n+1, 0);
        isFree = vi(n+1, true);
        isDone = vi(n+1, false);
        vi inEdge = arr;
        FOR(i, 0, n) {
            int x, y;
            cin >> x >> y;
            arr[x] = y;
            inEdge[y]++;
        }
        FORE(i, 1, n) {
            if (inEdge[i] == 0) {
                f = 0;
                DFS(i);
                int u = f;
                while (arr[u] != f) {
                    cnt[u] = cnt[f];
                    u = arr[u];
                }
                if (res < cnt[i]) {
                    res = cnt[i];
                    resc = i;
                }
            }
        }

        FORE(i, 1, n) {
            if (isFree[i]) {
                f = 0;
                DFS(i);
                int u = f;
                while (arr[u] != f) {
                    cnt[u] = cnt[f];
                    u = arr[u];
                }
                if (res <= cnt[i]) {
                    res = cnt[i];
                    resc = i;
                }
                if (res == cnt[i] && i < resc) {
                    res = cnt[i];
                    resc = i;
                }
            }
        }
        cout << "Case " << tc << ": " << resc << endl;
    }
    return 0;
}