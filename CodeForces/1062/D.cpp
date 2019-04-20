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

int n, base;
vvii arr;
bitset<200005> isFree;
ll res = 0, cnt;

int realIndex(int index) {
    return index+base;
}

void init() {
    for (int i = 2; i <= n; i++) {
        for (int j = 2*i; j <= n; j+=i) {
            arr[realIndex(i)].push_back({realIndex(j), j/i});
            arr[realIndex(i)].push_back({realIndex(-j), j/i});
            arr[realIndex(-i)].push_back({realIndex(j), j/i});
            arr[realIndex(-i)].push_back({realIndex(-j), j/i});
            arr[realIndex(j)].push_back({realIndex(i), j/i});
            arr[realIndex(j)].push_back({realIndex(-i), j/i});
            arr[realIndex(-j)].push_back({realIndex(i), j/i});
            arr[realIndex(-j)].push_back({realIndex(-i), j/i});
        }
    }
    isFree.set();
}

void DFS(int u) {
    isFree[u] = false;
    for (auto edge : arr[u]) {
        int v = edge.first;
        cnt += edge.second;
        if (isFree[v]) {
            // cerr << u << " " << v << "\n";
            DFS(v);
            
        }
    }
}

void vietnakid() {
    cin >> n;
    base = n;
    arr.resize(2*n+1);
    init();
    for (int i = 2; i <= n; i++) {
        if (isFree[realIndex(i)]) {
            cnt = 0;
            DFS(realIndex(i));
            res = max(res, cnt/2);
        }
    }
    cout << res << "\n";
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