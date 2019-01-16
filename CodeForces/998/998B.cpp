#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n, b;
    cin >> n >> b;
    vii arr(n+1, {0, 0});
    vi x(n+1);
    FORE(i, 1, n) {
        cin >> x[i];
        arr[i] = arr[i-1];
        if (x[i] % 2 == 0) {
            arr[i].first++;
        } else {
            arr[i].second++;
        }
    }
    int res = 0;
    int cost = 0;
    vi isFree(n+1, true);
    while (true) {
        int minn = INF, u = 0;
        FOR(i, 1, n) {
            if (arr[i].first == arr[i].second && isFree[i]) {
                if (minn > abs(x[i+1] - x[i])) {
                    minn = abs(x[i+1] - x[i]);
                    u = i;
                }
            }
        }
        // cerr << u << endl;
        if (u == 0 || minn + cost > b) {
            break;
        }
        isFree[u] = false;
        res++;
        cost += minn;
    }
    cout << res << endl;
    return 0;
}