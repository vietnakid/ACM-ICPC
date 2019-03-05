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

int numChild[150005], root[150005];
vi child[150005];

int getRoot(int u) {
    while (root[u] != u) {
        u = root[u];
    }
    return u;
}

void uni(int u, int v) {
    int rootU = getRoot(u);
    int rootV = getRoot(v);
    root[rootV] = rootU;
    child[rootU].push_back(rootV);
    root[u] = rootU;
    root[v] = rootU;
    
}

void trace(int u) {
    cout << u << " ";
    for (int i = 1; i < child[u].size(); i++) {
        // cerr << u << " " << child[u][i] << endl;
        trace(child[u][i]);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    int n; cin >> n;
    int u, v;
    for (int i = 1; i <= n; i++) {
        numChild[i] = 1;
        child[i].push_back(i);
        root[i] = i;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        uni(u, v);
    }
    // cerr << getRoot(5) << endl;
    trace(getRoot(u));
    return 0;
}