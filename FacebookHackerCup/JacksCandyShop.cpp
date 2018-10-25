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

ll n, m, a, b;
vi parent;
vvi child;
ll res;
vi c;
vector<priority_queue<int, vi, less<int> > > remain;

void calTree(int u) {
    remain[u].push(u);

    FOR(i, 0, (int)child[u].size()) {
        int v = child[u][i];
        calTree(v);
        if (remain[u].size() < remain[v].size()) {
            swap(remain[u], remain[v]);
        }
        while (remain[v].size() != 0) {
            int x = remain[v].top();
            remain[v].pop();
            remain[u].push(x);
        }
    }

    while (c[u] > 0 && remain[u].size() > 0) {
        int x = remain[u].top();
        // cerr << u << " " << x << endl;
        remain[u].pop();
        res += x;
        c[u]--;
    }
}

int main()
{
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    FORE(tc, 1, TC) {
        cerr << tc << endl;
        cout << "Case #" << tc << ": ";
        
        cin >> n >> m >> a >> b;

        parent = vi(n, 0);
        parent[0] = -1;
        child = vvi(n);
        res = 0;
        c = vi(n, 0);
        remain = vector<priority_queue<int, vi, less<int> > >(n);
        FOR(i, 1, n) {
            int x; cin >> x;
            parent[i] = x;
            child[x].push_back(i);
        }
        
        FOR(i, 0, m) {
            ll x = (a * i + b) % n;
            c[x]++;
        }
        calTree(0);
        
        cout << res << endl;
    }
    return 0;
}