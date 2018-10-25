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

int n;
vii arr;
vi s, ma;
vi rr;
int res = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    scanf("%d", &n);
    arr.resize(n);
    s.resize(n);
    ma.resize(n);
    rr.resize(n);
    FOR(i, 0, n) {
        int t, r;

        scanf("%d %d", &t, &r);
        arr[i].first = t+r;
        arr[i].second = t-r;
        rr[i] = arr[i].first;
    }
    sort(arr.begin(), arr.end());
    sort(rr.begin(), rr.end());

    s[0] = 1;
    ma[0] = 1;
    FOR(i, 1, n) {
        vi::iterator it = upper_bound(rr.begin(), rr.end(), arr[i].second);
        int j = distance(rr.begin(), it) - 1;
        // cerr << j << endl;
        if (j >= 0) {
            s[i] = ma[j] + 1;
        } else {
            s[i] = 1;
        }
        ma[i] = max(s[i], ma[i-1]);
        res = max(res, ma[i]);
    }
    cout << res << endl;
    return 0;
}