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

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1e9+7
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        vector<double> arr(n);
        double x, sum = 0, res1 = 0, res2 = 0;
        FOR(i, 0, n) {
            cin >> x;
            arr[i] = x*100;
            sum += arr[i];
        }
        sum /= n;
        int fs = floor(sum);
        int cs = fs+1;
        FOR(i, 0, n) {
            if (arr[i] < fs) {
                res1 += fs - arr[i];
            } else if (arr[i] > cs) {
                res2 += arr[i] - cs;
            }
        }
        // cerr << res1 << " " << res2 << " " << sum << endl;
        printf("$%.2f\n", max(res1/100, res2/100));
    }
    return 0;
}