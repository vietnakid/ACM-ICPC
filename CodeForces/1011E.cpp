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
    cin >> n >> m;
    vi arr(n);
    set<int> res;
    FOR(i, 0, n) {
        cin >> arr[i];
        arr[i] %= m;
    }
    
    int gcd = arr[0];
    FOR(i, 1, n) {
        gcd = GCD(gcd, arr[i]);
    }
    int x = 0;
    while (true) {
        x = (x + gcd) % m;
        if (res.find(x) == res.end()) {
            res.insert(x);
        } else {
            break;
        }
    }
    
    printf("%d\n", (int)res.size());
    for(set<int>::iterator it = res.begin(); it != res.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    return 0;
}