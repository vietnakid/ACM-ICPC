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

int n;
vvi arr;
vi visited, finish;
bool res;
int cnt = 1;

void DFS(int u) {
    visited[u] = true;
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        if (!visited[v]) {
            DFS(v);
        } else if (!finish[v]) {
            res = true;
        }
    }
    finish[u] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n;
    arr = vvi(n+1);
    visited = vi(n+1, false);
    finish = vi(n+1, false);
    res = false;
    FORE(i, 1, n) {
        int x;
        cin >> x;
        if (x <= n && x > 0) {
            arr[x].push_back(i);
        }
    }
    FORE(i, 1, n) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    if (res) {
        cout << "0" << endl;
    } else {
        cout << "1" << endl;
    }
    return 0;
}