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

int n, p;
vi isFree;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
//    freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> p;
    vii arr(n);
    isFree = vi(n, true);
    int res = 0;
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        res += y - x;
        arr[i] = {x, y};
    }
    FOR(t, 0, n-p) {
        int minn = INF;
        int x, y;
        FOR(i, 0, n) {
            if (isFree[i])
                FOR(j, 0, i) {
                    if (isFree[j]) {
                        int costi = arr[i].second - arr[i].first;
                        int costj = arr[j].second - arr[j].first;
                        int costij = min(arr[i].second, arr[j].second) - max(arr[i].first, arr[j].first);
                        if (costij < 0)
                            continue;
                        int d = costi + costj - costij;
                        if (d < minn) {
                            minn = d;
                            x = i;
                            y = j;
                        }
                    }
                }
        }
//        cout << x << " " << y << " " << minn << endl;
        res -= minn;
        isFree[y] = false;
        arr[x].first = max(arr[x].first, arr[y].first);
        arr[x].second = min(arr[x].second, arr[y].second);
    }
    cout << res << endl;
    return 0;
}
