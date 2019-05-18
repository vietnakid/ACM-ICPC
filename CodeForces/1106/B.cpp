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

ll cnt[100005], c[100005];
int n, m;
vii arr;

void vietnakid() {
    cin >> n >> m;
    for (int i =0 ; i < n; i++) cin >> cnt[i];
    for (int i = 0; i < n;i ++) {
        cin >> c[i];
        arr.push_back({c[i], i});
    }
    sort(arr.begin(), arr.end());
    int index = 0;
    for (int i = 0; i < m; i++) {
        ll t, d; cin >> t >> d;
        t--;
        ll sum = 0;
        while (d > 0) {
            if (cnt[t] > 0) {
                int eat = min(d, cnt[t]);
                sum += eat * c[t];
                cnt[t] -= eat;
                d -= eat;
            } else {
                if (index >= n) {
                    sum = 0;
                    break;
                }
                if (cnt[arr[index].second] == 0) index++;
                if (index >= n) {
                    sum = 0;
                    break;
                } else {
                    t = arr[index].second;
                }
            }
        }
        cout << sum << "\n";
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