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

ll f[1000005], sum[1000005];

ll cal(int i) {
    if (f[i] != -1) {
        return f[i];
    }
    ll & res = f[i];
    if (i % 2 == 0) {
        res = cal(i/2) + 1;
    } else {
        res = cal(i+1) + 1;
    }
    return res;
}

void vietnakid() {
    int T;
    // cin >> T;
    scanf("%d", &T);
    memset(f, -1, sizeof(f));
    f[1] = 0;
    sum[0] = 0;
    for (int i = 1; i < 1000001; i++) {
        f[i] = cal(i);
        sum[i] = f[i] + sum[i-1];
    }
    setbuf(stdout, NULL);
	for(int test_case = 0; test_case  < T; test_case++)
	{
        int a, b;
        scanf("%d %d", &a, &b);
        ll res = sum[b] - sum[a-1];
        // cout << "Case #" << test_case+1 << endl;
        printf("Case #%d\n%lld\n", test_case+1, res);
		// cout << res << endl;
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