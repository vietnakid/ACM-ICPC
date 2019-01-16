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

ll cal(ll n, ll k) {
    ll sum = ((n+2) * (n/k + 1)) / 2 - (n+1);
    return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    // for (int n = 1; n < 100; n++) {
        
    //     cerr << "n = " << n << endl;
    //     for (int k = 1; k <= n; k++) {
    //         ll sum = cal(n, k);
    //         cerr << "k = " << k << " " << sum << endl;
    //     }
    //     cerr << endl;
    // }
    ll n;
    cin >> n;
    set<ll> ss;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            ss.insert(cal(n, i));
            // cerr << i << " " << cal(n, i) << endl;
            
            if (i != n/i) {
                // cerr << n/i << " " << cal(n, n/i) << endl;
                ss.insert(cal(n, n/i));
            }
        }
    }
    for (auto &x : ss) {
        cout << x << " ";
    }
    return 0;
}