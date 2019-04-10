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

ll n, m;
ll arr[200005], s[200005];
ll res= INF;

ll sum(ll a) {
    return a * (a+1) / 2;
}

bool cmp(int a, int b) {
    return a > b;
}

void vietnakid() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1, cmp);

    for (int i = 1; i <= n; i++) {
        s[i] = s[i-1] + arr[i];
        ll left = 1, right = i;
        ll curDay = -1;
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll congDon = (i-1) / mid - 1;
            if (mid == 1) {
                congDon = i-1;
            }
            ll value;
            if (i % mid == 0 && mid != 1) {
                value = sum(congDon) * mid + (i-1)/mid * mid;
            } else {
                value = sum(congDon) * mid + (i-1)/mid * (i % mid);
            }
            
            if (s[i] - value >= m) {
                right = mid - 1;
                curDay = mid;
                // cerr << "i = " << i << " | day = " << mid << " | value = " << value << " | s[i] = " << s[i] << "\n";
                // cerr << congDon << "\n";
            } else {
                left = mid + 1;
            }
        }
        if (curDay != -1) {
            res = min(res, curDay);
        }
    }
    if (res == INF) {
        cout << -1 << "\n";
    } else {
        cout << res << "\n";
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