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
    int n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    string s; cin >> s;
    int state = s[0];
    vl arr(2, 0);
    int cur = state - '0';
    arr[cur] = 1;
    FOR(i, 0, n) {
        if (s[i] != state) {
            cur = 1 - cur;
            state = s[i];
            arr[cur]++;
        }
    }
    // cerr << arr[0] << " " << arr[1] << endl;
    if (arr[0] == 0 && arr[1] == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (arr[1] > arr[0]) {
        cout << (arr[1] - 2) * min(x,y) + y << endl;
    } else {
        cout << (arr[0] - 1) * min(x,y) + y << endl;
    }
    return 0;
}