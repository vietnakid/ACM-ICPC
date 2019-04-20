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

int n, m, k;
int cnt[100005];
int root[100005];
vector<pair<int, ii> > arr;

int getRoot(int u) {
    if (root[u] == 0) return u;
    return root[u] = getRoot(root[u]);
}

void unionRoot(int u, int v) {
    if (getRoot(u) == getRoot(v)) return;
    // cerr << u << " -- " << v << "\n";
    cnt[getRoot(v)] += cnt[getRoot(u)];
    root[getRoot(u)] = getRoot(v);
}

void input() {
    cin >> n >> m >> k;
    int P;
    for (int i = 0; i < k; i++) {
        int u; cin >> u;
        cnt[u] = 1;
        P = u;
    }
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        arr.push_back({c, {u, v}});
    }
    sort(arr.begin(), arr.end());
    int res = 0;
    for (auto x : arr) {
        int c = x.first;
        int u = x.second.first;
        int v = x.second.second;
        unionRoot(u, v);
        // cerr << u << " " << v << " " << c << "\n";
        if (cnt[getRoot(u)] == k) {
            res = c;
            break;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << res << " ";
    }
    cout << "\n";
}

void vietnakid() {
	input();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}