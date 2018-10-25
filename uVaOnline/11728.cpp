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

int sum(int n) {
    int res = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n/i) {
                res += i;
            } else {
                res += i;
                res += n/i;
            }
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
    int n, tc = 0;
    while (cin >> n) {
        if (n == 0) break;
        tc++;
        cout << "Case " << tc << ": ";
        bool check = false;
        FORD(i, n, 1) {
            if (sum(i) == n) {
                cout << i << endl;
                check = true;
                break;
            }
        }
        if (!check) {
            cout << -1 << endl;
        }
    }
    return 0;
}