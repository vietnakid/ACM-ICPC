#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    cin >> n;
    vi arr(n+1), p(n+1);
    FORE(i, 1, n) {
        int x;
        cin >> x;
        arr[i] = x;
        p[x] = i;
    }
    int res = 0;
    FORE(i, 1, n) {
        if (p[i] != i) {
            res++;
            int tmp = p[i];
            int h = arr[i];
            p[i] = i;
            arr[i] = i;
            p[h] = tmp;
            arr[tmp] = h;
            // FORE(j, 1, n) {
            //     cerr << arr[j] << " ";
            // }
            // cerr << endl;
        }
    }
    // cerr << res << endl;
    int peter = 3 * n;
    if ((peter - res) % 2 == 0) {
        cout << "Petr" << endl;
    } else {
        cout << "Um_nik" << endl;
    }
    return 0;
}