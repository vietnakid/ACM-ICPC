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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

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

vvi powerMatrix(vvi & arr, ll pow) {
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

ll n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m;
    if (n < m) {
        cout << 1 << endl;
        return 0;
    }
    vvi arr(m, vi(m));
    arr[0][0] = 1;
    arr[0][m-1] = 1;
    for (int i = 1; i < m; i++) {
        arr[i][i-1] = 1;
    }
    vvi pow = powerMatrix(arr, n-m+1);
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cerr << pow[i][j] << " ";
    //     }
    //     cerr << "\n";
    // }
    vvi fibo(m, vi(1, 1));
    ll res = multiplyMatrix(pow, fibo)[0][0];
    cout << res << endl;
    return 0;
}