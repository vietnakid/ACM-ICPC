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

vvi divisor(200005);
vector<map<int, int> > maxDist(200005);
vi value(200005);
vvi arr(200005);
int n;
int res = 0;

void init() {
    for (int i = 1; i <= n; i++) {
        int v = value[i];
        for (int j = 2; j*j <= v; j++) {
            if (v % j == 0) {
                divisor[i].push_back(j);
                maxDist[i][j] = 1;
            }
            while (v % j == 0) {
                v /= j;
            }
        }
        if (v > 1) {
            divisor[i].push_back(v);
            maxDist[i][v] = 1;
        }
    }
}

void DFS(int u, int father) {
    // cerr << u << " " << maxDist[u][2] << endl;
    for (auto &v : arr[u]) {
        if (v == father) {
            continue;
        }
        DFS(v, u);
        for (auto &c : divisor[u]) {
            res = max(res, maxDist[v][c] + maxDist[u][c]);
            maxDist[u][c] = max(maxDist[u][c], maxDist[v][c] + 1);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
        if (value[i] != 1) {
            res = 1;
        }
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    init();
    DFS(1, 0);
    cout << res << endl;
    return 0;
}