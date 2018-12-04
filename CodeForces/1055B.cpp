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
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll n, m, l;
vl arr;
int res = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m >> l;
    arr.resize(n);
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    bool isSmaller = true;
    FOR(i, 0, n) {
        if (isSmaller && arr[i] > l) {
            res++;
        }
        if (arr[i] <= l) {
            isSmaller = true;
        } else {
            isSmaller = false;
        }
    }

    FOR(t, 0, m) {
        int type; cin >> type;
        if (type == 0) {
            cout << res << endl;
        } else {
            ll p, d;
            cin >> p >> d;
            p--;
            if (arr[p] <= l && arr[p] + d > l) {
                if (n == 1) {   
                    res++;
                } else if (p == 0) {
                    if (arr[p+1] <= l) {
                        res++;
                    }
                } else if (p == n-1) {
                    if (arr[p-1] <= l) {
                        res++;
                    }
                } else {
                    // cerr << p+1 << " " << d << endl;
                    if (arr[p+1] > l && arr[p-1] > l) {
                        res--;
                    } else if (arr[p+1] <= l && arr[p-1] <= l) {
                        res++;
                    }
                }
            }
            arr[p] += d;
        }
    }
    return 0;
}