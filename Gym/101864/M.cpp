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

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    while (TC--) {
        vi res;
        cin >> n;
        vi arr(n);
        FOR(i, 0, n) cin >> arr[i];
        reverse(arr.begin(), arr.end());
        cin >> m;
        vi brr(m);
        FOR(i, 0, m) cin >> brr[i];
        reverse(brr.begin(), brr.end());
        FOR(i, 0, m-n+1) {
            int x = brr[i] / arr[0];
            res.push_back(x);
            int k = -1;
            FOR(j, i, i+n) {
                k++;
                brr[j] = brr[j] - (x * arr[k]);
            }
        }
        cout << res.size() << endl;
        FORD(i, res.size()-1, 0) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}