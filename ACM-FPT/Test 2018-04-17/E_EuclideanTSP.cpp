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

ld n, p, s, v, c;

ld calEqualtion(ld c) {
    ld res = (log(n) / log(2));
    res = pow(res, c*sqrt(2));
    res *= n;
    res = res / (p * 1e9);
    res += s * (1. + 1./c) / v;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    
    cin >> n >> p >> s >> v;
    ld left = 1e-3, right = 1000;
    ld res = INFLL;
    FOR(i, 0, 1000) {
        ld mid1 = (right - left) / 3 + left;
        ld mid2 = (right - left) / 3 * 2 + left;
        ld value1 = calEqualtion(mid1);
        ld value2 = calEqualtion(mid2);
//        printf("%.5Lf %.5Lf %.5Lf %.5Lf %.5Lf %.5Lf\n", left, right, value1, value2, mid1, mid2);
        if (value1 < value2) {
            right = mid2;
        } else {
            left = mid1;
        }
    }
    printf("%15.15Lf %15.15Lf\n", calEqualtion(left), left);
    return 0;
}
