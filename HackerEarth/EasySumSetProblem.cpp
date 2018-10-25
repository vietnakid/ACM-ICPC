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
    int n, m;
    set<int> a, c, b;
    cin >> n;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        a.insert(x);
    }
    cin >> m;
    FOR(i, 0, m) {
        int x;
        cin >> x;
        c.insert(x);
    }
    FORE(x, 1, 100) {
        bool check = true;
        for(set<int>::iterator it = a.begin(); it != a.end(); it++) {
            int y = *it;
            if (c.find(x+y) == c.end()) {
                check = false;
            }
        }
        if (check) {
            b.insert(x);
        }
    }
    for(set<int>::iterator it = b.begin(); it != b.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}