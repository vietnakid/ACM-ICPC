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
    string s, ss;
    vi b, a;
    while (cin >> s) {
        // cerr << "ok" << endl;
        ss = s;
        reverse(ss.begin(), ss.end());
        if (s == ss) {
            cout << s << endl;
            continue;
        }
        int n = s.size();
        b.resize(n);
        a.resize(n);
        b[0] = -1;
        int j = -1;
        int i = 0;
        while (i < n) {
            while (j >= 0 && ss[i] != ss[j]) {
                j = b[j];
                // cerr << j << " " << b[j] << endl;
            }
            i++; j++;
            b[i] = j;
            // cerr << i << " " << j << endl;
        }

        i = 0; j = 0;
        while (i < n) {
            while (j >= 0 && s[i] != ss[j]) {
                j = b[j];
            }
            i++; j++;
            a[i] = j;
        }
        // cerr << ss << endl;
        int res = a[n-1] + 1;
        // cerr << res << " " << n << endl;
        string _s = "";
        FORD(i, n - res - 1, 0) {
            _s.push_back(s[i]);
        }
        cout << s << _s << endl;
        // cerr << "ok" << endl;
    }
    return 0;
}