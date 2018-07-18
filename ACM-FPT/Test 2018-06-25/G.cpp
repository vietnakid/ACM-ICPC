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
    double d, v1, v2, a, b;
    cin >> d >> v1 >> v2 >> a >> b;
    double time = 0;
    if (v1 * a >= d) {
        time += d / v1;
        // cerr << 1 << endl;
        cout << ceil(time) << endl;
        return 0;
    }
    if (v1 * a + (v1-v2)*b <= esp) {
        cout << -1 << endl;
    } else {
        time = floor((d / (v1 * a + (v1-v2)*b)));
        time *= (a+b);
        d -= (time)*floor((d / (v1 * a + (v1-v2)*b)));
        // cerr << time << " " << d << endl;
        if (v1 * a >= d) {
            time += (double)(d) / (double)(v1);
            // cerr << 1 << endl;
            cout << ceil(time) << endl;
            return 0;
        } else {
            d -= (v1 * a);
            time += a;
            time += (double)(d) / (double)(v1-v2);
            // cerr << 2 << endl;
            cout << ceil(time) << endl;
            return 0;
        }
    }
    return 0;
}