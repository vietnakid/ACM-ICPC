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

ll n, k;
vi arr, BIT;

void update(int x) {
    while (x < 2005) {
        BIT[x]++;
        x += x & (-x);
    }
}

ll get(int x) {
    ll res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= x & (-x);
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    ll t;
    cin >> t;
    while (t--) {
        int result = 0;
        cin >> n >> k;
        arr = vi(n);
        for (auto & x : arr) cin >> x;
        for (int l = 0; l < n; l++) {
            BIT = vi(2005, 0);
            vi cnt(2005, 0);
            for (int r = l; r < n; r++) {
                int m = ceil((double)k / (double)(r-l+1));
                update(arr[r]);
                cnt[arr[r]]++;
                int left = 0, right = 2001;
                int res = -1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    ll value = get(mid);
                    if (value*m >= k) {
                        res = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                int f = cnt[res];
                int occurent = cnt[f];
                if (occurent > 0) {
                    result += 1;
                }
                // cerr << l << " " << r << " " << res << " " << f << " " << occurent << endl;
            }
        }
        cout << result << '\n';
    }
    return 0;
}