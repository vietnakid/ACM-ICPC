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

#define FOR(i, a, b) \
for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

ll trans(ll a, ll b) {
    if (a < b) {
        return INF;
    }
    ll res = 0;
    while (a > b) {
        res++;
        a = ceil(ld(a) / 2.);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    vi arr(2), brr(2);
    cin >> arr[0] >> arr[1];
    cin >> brr[0] >> brr[1];
    ll res = INF;
    res = min(res, trans(arr[0], brr[0]) + trans(arr[1], brr[1]));
    res = min(res, trans(arr[0], brr[1]) + trans(arr[1], brr[0]));
    if (res >= INF) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
