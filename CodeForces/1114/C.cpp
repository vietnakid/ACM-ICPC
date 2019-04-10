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

uint64_t n, b;
map<uint64_t, int> mp;

void vietnakid() {
    cin >> n >> b;
    for (uint64_t  i = 2; i*i <= b; i++) {
        while (b % i == 0) {
            mp[i]++;
            b /= i;
        }
    }
    if (b > 1) {
        mp[b]++;
    }
    uint64_t res = INFLL;
    for (auto u : mp) {
        uint64_t value = u.first;
        int occur = u.second;
        uint64_t cnt = 0;
        for (uint64_t i = value; i <= n; i *= value) {
            if (i % value != 0) break;
            cnt += n/i;
            // cerr << i << " " << cnt << " " << n/i << "\n";
        }
        // cerr << value << " | cnt = " << cnt << " | occur = " << occur << "\n";
        res = min(res, cnt/occur);
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