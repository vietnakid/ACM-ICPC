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
ll arr[200005], s[200005];
ll h;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
 	cin >> h >> n;
    ll minn = INFLL;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s[i] = s[i-1] + arr[i];
        minn = min(minn, s[i]);
    }
    if (-minn >= h) {
        for (int i = 1; i <= n; i++) {
            if (h + s[i] <= 0) {
                cout << i << "\n";
                return 0;
            }
        }
    }
    if (s[n] >= 0) {
        cout << "-1\n";
    } else {
        cerr << minn << "\n";
        ll r = ceil((h + minn) / -(double)s[n]);
        cerr << r << "\n";
        h = h + s[n] * r;
        cerr << h << "\n";
        for (int i = 1; i <= n; i++) {
            if (h + s[i] <= 0) {
                cout << r*n + i << "\n";
                return 0;
            }
        }
    }
    return 0;
}