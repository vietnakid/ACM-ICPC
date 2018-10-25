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
#define esp 1e-7
#define PI 3.14159265

ll nMod = 1e9 + 9;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    ll n;
    while(cin >> n) {
        int digits = log10(n);
        double ln10 = log10(n) + digits + 1;
        double hn10 = log10(n+1) + digits + 1;
        double L10 = log(10), L2 = log(2);
        double ln2, hn2;
        while(true) {
            hn10 += 1;
            ln10 += 1;
            ln2 = ln10 * L10 / L2;
            hn2 = hn10 * L10 / L2;
            
            if (floor(hn2) >= ln2) {
                printf("%d\n", (int)floor(hn2));
                break;
            }
        }
    }
    return 0;
}