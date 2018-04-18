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

vector<pair<ll, ll> > arr;
int n, k;

ll cal(ll a, ll b, ll c) {
    // cout << a << " "<< b << " " << c << endl;
    ll ap = 2*a;
    ll bp = b;
    ll x = -bp / ap;
    // cout << x << " " << a*x*x + b*x + c << endl;
    ll y = x+1;
    return min(a*x*x + b*x + c, a*y*y + b*y + c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
       // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    //     freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> k;
    arr = vector<pair<ll, ll> >(n);
    FOR (i, 0, n) {
        cin >> arr[i].first >> arr[i].second;
    }
    vvl f(n);
    FOR(i, 0, n) {
        f[i] = vl(k+1, INFLL);
    }
    ll asquare = 0, a2 = 0, xi = 0;
    FOR(ii, 0, n) {
        asquare += arr[ii].first * arr[ii].first * arr[ii].second;
        a2 += -2*arr[ii].first * arr[ii].second;
        xi += arr[ii].second;
        f[ii][1] = min(f[ii][1], cal(xi, a2, asquare));
    }
    
    
    FOR(i, 0, n)
    FOR(j, 2, k+1) {
        if (i < j)
            f[i][j] = 0;
        else {
            ll asquare = 0, a2 = 0, xi = 0;
            for (int ii = i; ii >= j-1; ii--){
                asquare += arr[ii].first * arr[ii].first * arr[ii].second;
                a2 += -2*arr[ii].first * arr[ii].second;
                xi += arr[ii].second;
                f[i][j] = min(f[i][j], f[ii-1][j-1] + cal(xi, a2, asquare));
                
            }
            
        }
    }
    cout << f[n-1][k] << endl;
    return 0;
}
