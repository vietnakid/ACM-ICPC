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
    int n, m, q;
    cin >> n >> m >> q;
    string s1, s2;
    cin >> s1 >> s2;
    vi arr(n, 0);
    FORE(i, 0, n-m) {
        if (i != 0) {
            arr[i] = arr[i-1];
        }
        bool check = true;
        int k = i;
        FOR(j, 0, m) {
            // cerr << s1[k] << " " << s2[j] << endl;
            if (s1[k] != s2[j]) {
                check = false;
                break;
            }
            k++;
        }
        if (check) {
            arr[i]++;
        }
        // cerr << arr[i] << " ";
    }
    // cerr << endl;
    if (n >= m)
        FOR(i, n-m+1, n) {
            arr[i] = arr[i-1];
        }
    FOR(i, 0, q) {
        int l, r;
        cin >> l >> r;
        r--; l--;
        int x, y;
        if (l == 0) {
            x = 0;
        } else {
            x = arr[l-1];
        }
        if (r < m-1) {
            y = 0;
        } else {
            y = arr[r-m+1];
        }
        // cerr << l << " " << r << " " << x << " " << y << endl;
        cout << max(y - x, 0) << endl;
    }
    return 0;
}