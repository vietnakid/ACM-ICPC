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

int f[1000005];

ll cal2(ll n) {
    ll sum = 0, step = 0, cnt = 1;
    while (sum < n) {
        if (sum + cnt <= n) {
            sum += cnt;
            step++;
            cnt++;
        } else {
            cnt = 1;
        }
    }
    // cerr << n << " " << step << "\n";
    return step;
}

ll cal(ll n) {
    return f[n];
}

void init() {
    memset(f, -1, sizeof(f));
    f[1] = 1;
    for (int i = 2; i < 1005; i++) {
        f[i] = cal2(i);
        for (int j = 1; j <= i/2; j++) {
            if (f[i] > f[j] + f[i-j]) {
                // cerr << "i = " << i << " | j = " << j << " | " << " .. " << f[i] << " | " << f[j] + f[i-j] << "\n";
                f[i] = min(f[i], f[j] + f[i-j]);
            }
        }
        // cerr << i << " " << f[i] << "\n";
        cerr << f[i] << " ";
    }
}

void vietnakid() {
    int T, test_case;
    cin >> T;
    init();

    // for (int i = 1; i < 10005; i++) {
    //     if (cal(i) != cal2(i))
    //         cerr << i << " " << cal(i) << " " << cal2(i) << "\n";
    // }
	// for(test_case = 0; test_case  < T; test_case++)
	// {
    //     ll a, b;
    //     cin >> a >> b;
    //     ll res = 0;
    //     for (ll i = a; i <= b; i++) {
    //         res = max(res, cal(i));
    //     }
    //     cout << "Case #" << test_case+1 << "\n";
	// 	cout << res << "\n";
    // }
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