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

int n, res = 0;
vector<string> arr;
int cnt[1000015];

void vietnakid() {
    int base = 500005;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int s = 0, mmin = INF, mmax = 0;
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == '(') {
                s++;
            } else {
                s--;
            }
            mmin = min(mmin, s);
            mmax = max(mmax, s);
        }
        
        if (s >= 0) {
            if (mmin >= 0) {
                cnt[s + base]++;
                // cerr << s << " " << s+base << " " << arr[i] << "\n";
            }
        } else {
            if (mmin == s) {
                cnt[s + base]++;
                // cerr << s << " " << s+base << " " << arr[i] << "\n";
            }
        }
    }
    res = cnt[base] / 2;
    for (int i = 1; i < 500005; i++) {
        res += min(cnt[base+i], cnt[base-i]);
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