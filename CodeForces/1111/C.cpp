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

ll n, k, a, b, n2;
map<int, int> BIT;
multiset<int> mulSet;
vi arr;

void putBIT(ll u) {
    while (u <= n2) {
        BIT[u]++;
        u += u & (-u);
    }
}

int getBIT(ll u) {
    int res = 0;
    while (u > 0) {
        res += BIT[u];
        u -= u & (-u);
    }
    return res;
}

ll getRangeBIT(int l, int r) {
    return getBIT(r) - getBIT(l-1);
}

ll getRange(int l, int r) {
    int cntR = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), r + 1));
    int cntL = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), l));
    return cntR - cntL;
}

ll solve(int l, int r) {
    ll cntRange = getRange(l, r);
    ll lengRange = r-l+1;
    if (cntRange > 0) {
        if (l==r) return b*cntRange;
        int mid = (l+r) / 2;
        ll curRes = b*cntRange*lengRange;
        ll splitRes = solve(l, mid) + solve(mid+1, r);
        return min(curRes, splitRes);
    } else {
        return a;
    }
}

void vietnakid() {
	cin >> n >> k >> a >> b;
    n2 = 1;
    for (int i = 1; i <= n; i++) {
        n2 *= 2;
    }
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        // putBIT(x);
        mulSet.insert(x);
    }
    for (auto x : mulSet) {
        arr.push_back(x);
    }
    cout << solve(1, n2) << "\n";
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