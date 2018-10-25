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

ll aMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll pow(ll a, ll m, ll nMod) {
    if (m == 0 && a != 0) return 1;
    if (m == 0) return 0;
    if (m == 1) return a;
    ll v = pow(a, m/2, nMod);
    v = (v * v) % nMod;
    if (m % 2 == 1) {
        v = (v * a) % nMod;
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    cin >> n;
    vl arr(n);
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    // cerr << pow(5, 81, nMod -1) << endl;
    vvl tich(n, vl(n, 1));

    FOR(i, 0, n) {
        tich[i][i] = arr[i];
    }
    FOR(k, 1, n) {
        FOR(i, 0, n) {
            int j = i + k;
            if (j < n) {
                tich[i][j] = pow(arr[i], tich[i+1][j], aMod-1);
                // cout << i << " " << j << " " << arr[i] << " " << tich[i+1][j] << " " << tich[i][j] << endl;
            }
            
        }
    }
    ll res = 0;
    FOR(i, 0, n) {
        res = (res + arr[i]) % aMod;
        FOR(j, i+1, n) {
            // res = 0;
            cout << i << " " << j << " "<< pow(arr[i], tich[i+1][j], aMod) << " " << res << endl;
            res = (res + pow(arr[i], tich[i+1][j], aMod)) % aMod;
        }
    }
    cout << res << endl;
    return 0;
}