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
vvi arr;
int n, m;
bool res;
vi color;

void DFS(int u, int c) {
    color[u] = c;
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        if (color[v] != -1) {
            if (color[v] == c) {
                res = false;
            }
        } else {
            DFS(v, 1 - c);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while(true){
        cin >> n;
        if (n == 0) break;
        cin >> m;
        arr = vvi(n);
        FOR(i, 0, m) {
            int x, y;
            cin >> x >> y;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        color = vi(n, -1);
        res = true;
        DFS(0, 0);
        if (res) {
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
    }
    return 0;
}