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

int n;
int arr[200005];
ll res = 0;
map<int, ll> mp;

void vietnakid() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[abs(arr[i])]++;
    }
    for (auto v : mp) {
        res += v.second * (v.second-1) / 2;
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            int cnt = distance(upper_bound(arr, arr+n, arr[i]), upper_bound(arr, arr+n, arr[i]*2));
            cnt += distance(lower_bound(arr, arr+n, -2*arr[i]), lower_bound(arr, arr+n, -arr[i]));
            // cerr << cnt << "\n";
            res += cnt;
        } else if (arr[i] < 0) {
            int cnt = distance(upper_bound(arr, arr+n, -arr[i]), upper_bound(arr, arr+n, -arr[i]*2));
            cnt += distance(lower_bound(arr, arr+n, 2*arr[i]), lower_bound(arr, arr+n, arr[i]));
            // cerr << cnt << "\n";
            res += cnt;
        }
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