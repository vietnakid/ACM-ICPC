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
    int TC; cin >> TC;
    while (TC--) {
        ll a, b, n, m, r = 1;
        cin >> a >> b >> n >> m;
        FOR(i, 0, m) r *= 10;
        vl arr;
        arr.push_back(a % r);
        arr.push_back(b % r);
        while (true) {
            arr.push_back((arr[arr.size()-1] + arr[arr.size() - 2]) % r);
            // cerr << arr[arr.size() -1] << endl;
            if (arr[arr.size() - 2] == arr[0] && arr[arr.size() - 1] == arr[1]) {
                break;
            }
        }
        arr.pop_back();
        arr.pop_back();
        cout << arr[n % arr.size()] << endl;
    }
    return 0;
}