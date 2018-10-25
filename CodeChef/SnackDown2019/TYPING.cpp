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

double cal(string s) {
    int pre = 0;
    int res = 0;
    for(char c : s) {
        if (c == 'f' || c == 'd') {
            if (pre != -1) {
                res += 2;
            } else {
                res += 4;
            }
            pre = -1;
        } else {
            if (pre != 1) {
                res += 2;
            } else {
                res += 4;
            }
            pre = 1;
        }
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        int res = 0;
        map<string, int> mp;
        FOR(i, 0, n) {
            string s;
            cin >> s;
            if (mp.find(s) != mp.end()) {
                res += mp[s]/2;
            } else {
                mp[s] = cal(s);
                res += mp[s];
            }
            // cerr << mp[s] << endl;
        }
        cout << res << endl;
    }
    return 0;
}