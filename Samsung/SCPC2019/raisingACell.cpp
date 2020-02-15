#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<ll, ll> ii;
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
vii arr;
ll a, b;

bool canSolve(ll m) {
    ll minl = a;
    for (int i = 0; i < n; i++) {
        if (minl <= b && arr[i].first - m >= minl) {
            // cerr << m << " " << minl << "\n";
            return true;
        }
        if (arr[i].second < m) {
            minl = max(arr[i].first + m, minl);
        }
    }
    if (minl <= b) {
        // cerr << m << " " << minl << "\n";
        return true;
    } 

    return false;
}

void vietnakid() {
    int T, test_case;
    cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> a >> b;
        a *= 2;
        b *= 2;
        cin >> n;
        ll res = 0;
        arr.clear();
        arr.resize(n);
        ll l = 0, r = INFLL;
        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            x *= 2;
            y *= 2;
            arr[i] = {x, abs(y)};
        }
        sort(arr.begin(), arr.end());
        while (l <= r) {
            ll m = (l + r) / 2;
            if (canSolve(m)) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << "Case #" << test_case+1 << endl;
		cout << res << endl;
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
 	// cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}