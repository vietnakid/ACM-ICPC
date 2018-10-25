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
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int k, n, m;
    double base;
    cin >> base >> k >> n >> m;
    vii arr(n), brr(m);
    FOR(i, 0, n) {
        int x;
        cin >> x;
        arr[i] = {x, i};
    }
    FOR(i, 0, m) {
        int x;
        cin >> x;
        brr[i] = {x, i};
    }
    sort(arr.rbegin(), arr.rend());
    sort(brr.rbegin(), brr.rend());
    vi suma(n+1, 0), sumb(m+1, 0);
    FORE(i, 1, n) {
        suma[i] = arr[i-1].first + suma[i-1];
        // cerr << arr[i-1].first << " " << arr[i-1].second << endl;
    }
    FORE(i, 1, m) {
        sumb[i] = brr[i-1].first + sumb[i-1];
        // cerr << brr[i-1].first << endl;
    }
    double res = 0;
    int resa, resb;
    FORE(i, 0, min(n, k)) {
        double a = suma[i];
        int r = min(k - i, m);
        double b = sumb[r];
        if ((a + base)*(100 + b)/100 >= res) {
            res = (a + base)*(100 + b)/100;
            resa = i;
            resb = r;
        }
    }

    cout << resa << " " << resb << endl;
    if (resa > 0) {
        FOR(i, 0, resa) {
            cout << arr[i].second+1 << " ";
        }
        cout << endl;
    }
    if (resb > 0) {
        FOR(i, 0, resb) {
            cout << brr[i].second+1 << " ";
        }
        cout << endl;
    }
    return 0;
}