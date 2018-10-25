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

int test(int n) {
    int sum = 0;
    FOR(i, 1, n) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return 0;
    }
    if (sum < n) {
        return 1;
    }
    return 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    printf("PERFECTION OUTPUT\n");
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            printf("END OF OUTPUT\n");
            break;
        }
        printf("%5d  ", n);
        int res = test(n);
        cerr << res << endl;
        if (res == 0) {
            printf("PERFECT\n");
        } else if (res == 1) {
            printf("DEFICIENT\n");
        } else {
            printf("ABUNDANT\n");
        }
    }
    return 0;
}