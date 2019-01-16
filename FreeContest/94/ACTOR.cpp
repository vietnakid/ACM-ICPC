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

ll ca, t, n;
ll a[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);   
    cin >> ca;
    cin >> t;
    while (t--) {
        cin >> n >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        if (a[2] == n && a[1] == n) cout << a[0] << endl;
        else if (ca == 1) {
            ll ab = ((a[0]+a[1]) % n >= a[0] && a[1] != n) ? 0 : (a[0]+a[1]) % n;
            ll ac = ((a[0]+a[2]) % n >= a[0] && a[2] != n) ? 0 : (a[0]+a[2]) % n;
            ll bc = ((a[1]+a[2]) % n >= a[1] && a[2] != n) ? 0 : (a[1]+a[2]) % n;
            ll res = ((ab + a[2]) % n >= ab && a[2] != n) ? 0 : (ab + a[2]) % n;
            res = min(res, ((ac + a[1]) % n >= ac && a[1] != n) ? 0 : (ac + a[1]) % n);
            res = min(res, ((bc + a[0]) % n >= bc && a[0] != n) ? 0 : (bc + a[0]) % n);
            cout << res << endl;
        } else {
            ll res = min(a[0], min(a[1], a[2]));
            cout << res << endl;
        }
    }
    return 0;
}