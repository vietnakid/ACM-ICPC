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
vi maxl(5005, INF), cnt(5005);
int maxCnt, t;

int calLeng(int u, int v) {
    if (v < u) {
        v += n;
    }
    return v - u;
}

void vietnakid() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        maxl[u] = min(maxl[u], calLeng(u, v));
    }
    for (int i = 1; i <= n; i++) {
        if (maxl[i] == INF) maxl[i] = 0;
        // cerr << i << " " << cnt[i] << " " << maxl[i] << "\n";
        maxCnt = max(maxCnt, cnt[i]);
        if (maxCnt < cnt[i]) {
            maxCnt = cnt[i];
            t = 1;
        }
        if (maxCnt == cnt[i]) {
            t++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int passed = max(0, maxCnt - 1);
        int res = 0;
        set<int> remain;
        for (int j = 0; j < n; j++) {
            int pos = (i + j);
            if (pos > n) pos -= n;
            int remain = cnt[pos] - passed;
            if (remain == 1) {
                res = max(res, j + maxl[pos]);
            } else if (remain == 0) {
                if (pos != i)
                    res = max(res, maxl[pos] - calLeng(pos, i));
            }
            // cerr << "start = " << i << " | cur = " << pos << " | remain = " << remain << " | res = " << res <<  "\n";
        }
        cout << res + passed*n << " ";
    }
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