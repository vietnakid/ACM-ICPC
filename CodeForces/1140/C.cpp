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

vii arr;
multiset<int> ms;
ll totalleng = 0, res = 0;

void vietnakid() {
	int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int l, f; cin >> l >> f;
        arr.push_back({-f, l});
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        ms.insert(-arr[i].second);
        totalleng += arr[i].second;
        if (ms.size() > k) {
            ll l = *prev(ms.end());
            totalleng += l;
            ms.erase(prev(ms.end()));
        }
        // cerr << totalleng << " " << arr[i].first << "\n";
        res = max(res, -totalleng * arr[i].first);
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