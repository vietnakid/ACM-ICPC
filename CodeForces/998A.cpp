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

int n;
vi arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n;
    arr = vi(n);
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    FOR(i, 1, (1 << n) - 1) {
        int suma = 0;
        int sumb = 0;
        int k = 0;
        FOR(j, 0, n) {
            if (i & (1 << j)) {
                suma += arr[j];
                k++;
            } else {
                sumb += arr[j];
            }
        }
        if (suma != sumb) {
            cout << k << endl;
            FOR(j, 0, n) {
                if (i & (1 << j)) {
                    cout << (j + 1) << endl;
                }
            }
            return 0;
        }
        
    }
    cout << -1 << endl;
    return 0;
}