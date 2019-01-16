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

ll n, t;
vl arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> t;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll s0 = 0, s1 = 0, e0 = 0, e1 = 0;
    for (int i = 0; i < n; i++) {
        s0 = e0;
        e0 = s0 + arr[i];
        s1 = max(e0, e1);
        e1 = s1 + arr[i];
        // cerr << s0 << " " << e0 << " " << s1 << " " << e1 << endl;
        ll m = ((t - s0) / (s1 - s0)) + 1;
        // cerr << m << endl;
        if (s0 + (m-1) * (s1 - s0) + arr[i] <= t) {
            if (m+1 < 1) {
                cout << 1 << endl;
            } else {
                cout << m+1 << endl;
            }
            
        } else {
            if (m < 1) {
                cout << 1 << endl;
            } else {
                cout << m << endl;
            }
            
        }
    }
    return 0;
}