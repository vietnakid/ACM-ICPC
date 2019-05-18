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

int n, m;
vvi arr(500005);
bitset<500005> isFree;
int cnt = 0;
int group[500005], resGroup[500005];

void DFS(int u) {
    isFree[u] = false;
    group[u] = cnt;
    resGroup[cnt]++;
    for (auto v : arr[u]) {
        if (isFree[v]) {
            DFS(v);
        }
    }
}

void vietnakid() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        int x = 0;
        if (k > 0)
            cin >> x;
        for (int j = 1; j < k; j++) {
            int y; cin >> y;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
    }

    isFree.set();
    for (int i = 1; i <= n; i++) {
        if (isFree[i]) {
            cnt++;
            DFS(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << resGroup[group[i]] << " ";
    }
    cout << "\n";
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