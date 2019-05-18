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
ll res[100005];

ll cal(ll m) {
    return (m+1)*m/2;
}

ll findStart() {
    ll left = 1, right = n;
    ll res = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll sum = cal(mid+k-1) - cal(mid-1);
        // cerr << mid << " " << sum << "\n";
        if (sum > n) {
            right = mid - 1;
        } else {
            res = mid;
            left = mid+1;
        }
    }
    return res;
}

void vietnakid() {
    cin >> n >> k;
    ll start = findStart();
    cerr << start << "\n";
    ll c = start;
    ll p = 0;
    for (int i = 0; i < k; i++) {
        p += c;
        c *= 2;
        if (p >= n) break;
    }
    cerr << p << "\n";
    if (p < n) {
        cout << "NO\n";
        return;
    }
    ll sum = cal(start+k-1) - cal(start-1);
    for (int i = 1; i <= k; i++) {
        res[i] = start+i-1;
    }
    int t = k;
    while (sum < n) {
        for (int i = t; i <= k; i++) {
            ll moreValue = res[i-1]*2 - res[i];
            // cerr << sum << " i = " << i << " value = " << moreValue << "\n";
            if (sum + moreValue > n) {
                moreValue = n - sum;
                res[i] += moreValue;
                sum += moreValue;    
                break;
            }
            sum += moreValue;
            res[i] += moreValue;
        }
        t--;
    }
    cout << "YES\n";
    for (int i = 1; i <= k; i++) {
        cout << res[i] << " ";
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