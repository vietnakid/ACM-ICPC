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

ll n, k, res = 0, cnt;
vii arr[100005];
bitset<100005> isFree;

ll powMod(ll a, ll n) {
	if (n == 0 && a != 0) return 1;
    if (n == 0 && a == 0) return 0;
	if (n == 1) return a;
	ll b = powMod(a, n >> 1);
	ll res = (b * b) % nMod;
	if (n & 1) res = (res * a) % nMod;
	return res;
}

void DFS(int u) {
    cnt++;
    isFree[u] = false;
    for (ii x: arr[u]) {
        int v = x.first;
        int t = x.second;
        if (t == 0 && isFree[v]) {
            DFS(v);
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
    cin >> n >> k;
 	for (int i = 0; i < n; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        arr[u].push_back({v, x});
        arr[v].push_back({u, x});
    }
    isFree.set();
    res = powMod(n, k);
    // cerr << res << "\n";
    for (int i = 1; i <= n; i++) {
        if (isFree[i]) {
            cnt = 0;
            DFS(i);
            res = (res - powMod(cnt, k)) % nMod;
            if (res < 0) {
                res += nMod;
            }
            // cerr << cnt << " " << powMod(cnt, k) << " " << res << "\n";
        }
    }
    cout << res << "\n";
    return 0;
}