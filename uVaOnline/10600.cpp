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

int n, m;
vi root;
vector< pair<int, pair<ii, int> > > arr;

int findRoot(int u) {
    while (root[u] != -1) {
        u = root[u];
    }
    return u;
}

void connectRoot(int u, int v) {
    root[findRoot(v)] = findRoot(u);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int tc = 0;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;

        arr.clear();
        FOR(i, 0, m) {
            int u, v, x;
            cin >> u >> v >> x;
            arr.push_back({x, {{u, v}, true}});
        }
        sort(arr.begin(), arr.end());
        vi brr;
        int res = 0;

        root = vi(n+1, -1);        
        FOR(i, 0, arr.size()) {
            pair<int, pair<ii, int> > node = arr[i];
            int u = node.second.first.first;
            int v = node.second.first.second;
            int x = node.first;
            // cerr << u << " " << v << " " << x << endl;
            if (findRoot(u) != findRoot(v)) {
                connectRoot(u, v);
                brr.push_back(i);
                res += x;
            } 
        }
        cout << res << " ";
        res = INF;
        FOR(j, 0, (int)brr.size()) {
            int rr = 0;
            arr[brr[j]].second.second = false;
            root = vi(n+1, -1);
            // cerr << brr.size() << endl;
            int cnt = 0;
            FOR(i, 0, arr.size()) {
                pair<int, pair<ii, int> > node = arr[i];
                int u = node.second.first.first;
                int v = node.second.first.second;
                int x = node.first;
                bool state = node.second.second;
                if (!state) {
                    continue;
                }
                if (findRoot(u) != findRoot(v)) {
                    connectRoot(u, v);
                    rr += x;
                    cnt++;
                } 
            }
            if (cnt == n-1)
                res = min(res, rr);
            arr[brr[j]].second.second = true;
        }
        cout << res << endl;
    }
    return 0;
}
