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
    while (true) {
        meHere:
        int n;
        cin >> n;
        if (n < 0) {
            break;
        }
        FORD(i,   ceil(sqrt(n)), 1) {
            int m = n;
            bool check = true;
            FOR(j, 0, i) {
                if (m % i != 1) {
                    check = false;
                    break;
                }
                m = (m / i) * (i-1);
            }
            if (m % i != 0) {
                check = false;
            }
            if (check) {
                printf("%d coconuts, %d people and 1 monkey\n", n, i);
                goto meHere;
            }
        }
        printf("%d coconuts, no solution\n", n);
    }
    return 0;
}