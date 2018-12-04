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
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m, k;
vvi arr;
queue<int> q;
vi d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    scanf("%d %d %d", &n, &m, &k);
    d.resize(n+1, -1);
    arr.resize(n+1);
    FOR(i, 0, k) {
        int x;
        scanf("%d", &x);
        q.push(x);
        d[x] = 0;
    }
    FOR(i, 0, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        arr[v].push_back(u);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto x : arr[u]) {
            if (d[x] == -1) {
                d[x] = d[u] + 1;
                q.push(x);
            }
        }
    }
    FORE(i, 1, n) {
        printf("%d\n", d[i]);
    }
    return 0;
}