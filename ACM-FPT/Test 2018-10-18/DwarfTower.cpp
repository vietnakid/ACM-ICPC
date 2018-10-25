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

vi f;
vi isDone;
vector< vector<ii> > arr;
int n, m;

void dijkstra(){
    while (true) {
        int mn = INF;
        int u = -1;
        FORE(i, 1, n) {
            if (f[i] < mn && !isDone[i]) {
                mn = f[i];
                u = i;
            }
        }
        if (u == -1) {
            break;
        }
        isDone[u] = true;
        FOR(i, 0, arr[u].size()) {
            int a = arr[u][i].first;
            int v = arr[u][i].second;
            if (f[u] + f[v] < f[a]) {
                f[a] = f[u] + f[v];
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    scanf("%d %d", &n, &m);
    f.resize(n+1);
    arr.resize(n+1);
    isDone.resize(n+1, false);
    FORE(i, 1, n) scanf("%d", &f[i]);
    int a, b, c;
    FOR(i, 0, m) {
        scanf("%d %d %d", &a, &b, &c);
        arr[b].push_back({a, c});
        arr[c].push_back({a, b});
    }
    dijkstra();
    cout << f[1] << endl;
    return 0;
}