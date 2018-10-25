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
    int TC; scanf("%d", &TC);
    FORE(tc, 1, TC) {
        printf("Case %d: ", tc);
        int n, p;
        scanf("%d %d", &n, &p);
        int s, e;
        vii arr;
        FOR(i, 0, n) {
            scanf("%d %d", &s, &e);
            arr.push_back({s, -1});
            arr.push_back({e, 1});
        }
        sort(arr.begin(), arr.end());
        int j = -1;
        int cur = 0;
        int res = INF;
        int tmp = 0;
        FOR(i, 0, 2*n) {
            if (arr[i].second == 1) {
                j = max(i, j);
                tmp = max(tmp, cur);
                while (tmp < p && j < 2*n-1) {
                    j++;
                    if (arr[j].second == -1) {
                        tmp++;
                    }
                }
                if (tmp >= p) {
                    res = min(res, arr[j].first - arr[i].first);
                }
                // cerr << tmp << " " << i << " " << j << " " << arr[i].first << " " << arr[j].first << endl;
                tmp--;
            }
            cur -= arr[i].second;
        }
        printf("%d\n", res);
    }
    return 0;
}