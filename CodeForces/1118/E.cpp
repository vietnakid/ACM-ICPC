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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

ll n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    scanf("%lld %lld", &n, &k);
    if (k*(k-1) < n) {
        printf("No\n");
    } else {
        ll cnt = 0;
        printf("Yes\n");
        for (int i = 1; i < k; i++) {
            for (int j = i+1; j <= k; j++) {
                printf("%d %d\n", i, j);
                cnt++;
                if (cnt == n) {
                    return 0;
                }
                printf("%d %d\n", j, i);
                cnt++;
                if (cnt == n) {
                    return 0;
                }
            }
        }
    }
    return 0;
}