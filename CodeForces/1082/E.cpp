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

int n, c;
map<int, vi> mp;
int res = 0;
int arr[500005], sum[500005];

void vietnakid() {
	cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        arr[i] = x;
        mp[x].push_back(i);
        sum[i] = sum[i-1] + (c == x);
    }
    for (auto u : mp) {
        int x = u.first;
        if (x == c) res = max(res, (int)mp[x].size());
        else {
            vi & vec = mp[x];
            int m = vec.size();
            int curRes = 0;
            int resIndex = 0;
            for (int i = 0; i < m; i++) {
                if (sum[vec[i]-1] + 1 > curRes + i - resIndex) {
                    curRes = sum[vec[i]-1] + 1;
                    resIndex = i;
                }
                // cerr << x << " " << curRes << " " << resIndex << "\n";
                res = max(res, curRes + i - resIndex + sum[n] - sum[vec[i]]);
            }
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