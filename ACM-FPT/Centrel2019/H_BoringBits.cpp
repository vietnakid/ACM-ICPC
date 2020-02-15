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

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

vvi multiplyMatrix(vvi & arr, vvi & brr) {
    int n = arr.size();
    int m = brr[0].size();
    int p = brr.size();
    vvi res(n, vi(m, 0));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            FOR(k, 0, p) {
                res[i][j] = ((ll)res[i][j] + (ll)arr[i][k]*(ll)brr[k][j]) %  nMod;
            }
        }
    }
    return res;
}

vvi powerMatrix(vvi & arr, ll pow = nMod) {
    if (pow == 0) {
        return vvi(arr.size(), vi(arr[0].size(), 0)); // Depend on case
    }
    if (pow == 1) {
        return arr;
    }
    vvi res = powerMatrix(arr, pow/2);
    res = multiplyMatrix(res, res);
    if (pow % 2 != 0) {
        res = multiplyMatrix(res, arr);
    }
    return res;
}


int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> k;
    ll f[n+1][k+1];
    memset(f, 0, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            f[i][j] = f[i-1][k] + f[i-1][j-1];
        }
    }
    return 0;
}
