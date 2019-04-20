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

int n, q;
vl arr, d, s;

void vietnakid() {
	cin >> n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    d.resize(n, 0);
    for (int i = 1; i < n; i++) {
        d[i] = arr[i] - arr[i-1];
        // cerr << d[i] << " ";
    }
    // cerr << "\n";
    sort(d.begin(), d.end());
    s.resize(n, 0);
    for (int i = 1; i < n; i++) {
        s[i] = d[i] + s[i-1];
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        ll l, r; cin >> l >> r;
        ll leng = r - l + 1;
        ll pos = distance(d.begin(), upper_bound(d.begin(), d.end(), leng));
        // cerr << pos << "\n";
        ll res = s[pos-1] + leng*(n-pos+1);
        cout << res << " ";
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