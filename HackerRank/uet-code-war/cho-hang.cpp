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

int n, t;
vi arr;

void vietnakid() {
	cin >> n >> t;
    arr.resize(n+1);
    for (int i = 0; i< n; i++) cin >> arr[i];
    for (int i =n-2; i >= 0; i--) arr[i] += arr[i+1];
    ll res = 0;
    vi brr = arr;
    reverse(brr.begin(), brr.end());
    for (int i = 0; i < n; i++) {
        int value = arr[i+1] + t + 1;
        int pos = distance(brr.begin(), lower_bound(brr.begin(), brr.end(), value)) - 1;
        pos = n-pos;
        res += i - pos + 1;
        // cerr << arr[i] << " " << value << "\n";
        // cerr << pos << " " << i << " " << res << "\n";
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