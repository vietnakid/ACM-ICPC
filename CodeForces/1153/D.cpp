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

int n;
int t[300005];
vi arr[300005];
int d[300005];
int cnt = 0;

void DFS(int u) {
    if (arr[u].size() == 0) {
        d[u] = 1;
        cnt++;
        return;
    }
    if (t[u] == 1) {
        d[u] = INF;
    } else {
        d[u] = 0;
    }
    for (auto v : arr[u]) {
        DFS(v);
        if (t[u] == 1) {
        d[u] = min(d[u], d[v]);
        } else {
            d[u] += d[v];
        }   
    }
}

void vietnakid() {
	cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 2; i <= n; i++) {
        int u; cin >> u;
        arr[u].push_back(i);
    }
    DFS(1);
    cout << cnt-d[1]+1 << "\n";
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