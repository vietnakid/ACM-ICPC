#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    cin >> n;
    vl a(n), b(n), c(n);
    FOR (i, 0, n) {
    	cin >> a[i] >> b[i] >> c[i];
    }
    vvl f(n);
    FOR(i, 0, n)
    	f[i] = vl(3);
    f[0][0] = a[0];
    f[0][1] = -INFLL;
    f[0][2] = 0;
    FOR(i, 1, n) {
    	f[i][0] = f[i-1][2] + a[i];
    	f[i][2] = max(f[i-1][0], max(f[i-1][1], f[i-1][2]));
    	f[i][1] = max(f[i-1][1]-b[i-1]+c[i-1], f[i-1][0]-a[i-1]+b[i-1]) + b[i];
    }
    cout << max(f[n-1][0], max(f[n-1][1], f[n-1][2])) << endl;
    return 0;
}