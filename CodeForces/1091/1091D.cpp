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

ll nMod = 998244353;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
vi arr, brr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    // for (int i = 1; i <= n; i++) {
    //     arr.push_back(i);
    // }
    // do {
    //     for (auto &x : arr) {
    //         brr.push_back(x);
    //     }
    // } while (next_permutation(arr.begin(), arr.end()));
    // int cnt = 0, dem = 0;
    // vector<int> counting(100, 0);
    // for (int i = 0; i < brr.size() - n + 1; i++) {
    //     int sum = 0;
    //     for (int j = i; j < i+n; j++) {
    //         // cerr << brr[j] << " ";
    //         sum += brr[j];
    //     }
    //     // cerr << sum << endl;
    //     if (sum == (n*(n+1)/2)) {
    //         cnt++;
    //         dem++;
    //     }
    //     if ((i+1) % (n) == 0) {
    //         // cerr << endl;
    //         // cerr << dem << endl;
    //         counting[dem]++;
    //         // if (dem == 1) break;
    //         dem = 0;
    //     } 
    // }
    // cout << cnt << endl;

    ll res = 0;
    ll cur = n;
    ll x = 2;
    for (ll i = n-2; i > 0; i--) {
        res = (res + (x*((i * cur) % nMod) % nMod)) % nMod;
        cur = (cur * (i+1)) % nMod;
        x++;
    }
    res = (res + n) % nMod;
    cout << res << endl;
    return 0;
}