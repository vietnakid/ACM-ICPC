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
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        int res = 0;
        int n;
        cin >> n;
        vector<string> arr(n);
        FOR(i, 0, n) {
            cin >> arr[i];
        }
        FOR(i, 0, n) {
            FOR(j ,0, n) {
                if (arr[i][j] == 'x') {
                    res++;
                    int tmp = i;
                    while(i < n-1 && arr[i+1][j] != '.') {
                        i++;
                        arr[i][j] = '.';
                    }
                    i = tmp;
                    tmp = j;
                    while(j < n-1 && arr[i][j+1] != '.') {
                        j++;
                        arr[i][j] = '.';
                    }
                    j = tmp;
                }
            }
        }
        printf("Case %d: %d\n", tc, res);
    }
    return 0;
}