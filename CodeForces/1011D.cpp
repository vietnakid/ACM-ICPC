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
    int m, n;
    cin >> m >> n;
    vi arr(n);
    FOR(i, 0, n) {
        cout << 1 << endl;
        fflush(stdout);
        int ans;
        cin >> ans;
        if (ans == 0) {
            return 0;
        } else {
            if (ans == -1) {
                arr[i] = 0;
            } else {
                arr[i] = 1;
            }
        }
    }
    int low = 1, high = m;
    int i = 0;
    while (true) {
        int m = (low + high) / 2;
        cout << m << endl;
        fflush(stdout);
        int ans;
        cin >> ans;
        if (ans == 0 || ans == -2) {
            return 0;
        } else {
            if (arr[i]) {
                if (ans == -1) {
                    high = m-1;
                } else {
                    low = m+1;
                }
            } else {
                if (ans == -1) {
                    low = m+1;
                } else {
                    high = m-1;
                }
            }
        }
        i = (i+1) % n;
    }
    return 0;
}