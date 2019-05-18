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

int n, k;
int c[100005], d[100005];
int rmqc[100005][20], rmqd[100005][20];

void init() {
    memset(rmqc, 0, sizeof(rmqc));
    memset(rmqd, 0, sizeof(rmqd));
    for (int i = 0; i < n; i++) {
        rmqc[i][0] = c[i];
        rmqd[i][0] = d[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            rmqc[i][j] = max(rmqc[i][j-1], rmqc[i+ (1 << (j-1))][j-1]);
            rmqd[i][j] = max(rmqd[i][j-1], rmqd[i+ (1 << (j-1))][j-1]);
        }
    }
}

int query(int l, int r) {
    int j = (int)log2(r-l+1);
    int resc = max(rmqc[l][j], rmqc[r-(1<<j)+1][j]);
    int resd = max(rmqd[l][j], rmqd[r-(1<<j)+1][j]);
    // cerr << l << " " << r << " || j = " << j << " || " << resc << " " << resd << "\n";
    // cerr << rmqc[l][j] << " ?? " << rmqc[1][1] << " || " << r-(1<<j)+1 << "\n";
    return abs(resc - resd);
}

void vietnakid() {
    int TC; 
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) scanf("%d", &c[i]);
        for (int i = 0; i < n; i++) scanf("%d", &d[i]);
        init();
        ll res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (query(i, j) <= k) {
                    // cerr << i+1 << " " << j+1 << "\n";
                    res++;
                }
            }
        }
        printf("Case #%d: %lld\n", tc , res);
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