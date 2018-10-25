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

int findSwaps( int n, vi b)
{
int count = 0, i, j, temp;
for( i = 0; i < n; i++ ) {
for( j = 0; j < n - 1; j++ ) {
if( b[j] > b[j+1] ) {
temp = b[j];
b[j] = b[j+1];
b[j+1] = temp;
count++;
}
}
}
return count;
}

void test(int n) {
    ll total = 0;
    vi arr(n, 0);
    FOR(i, 0, n) arr[i] = i;
    vi res(n*(n-1)/2 + 1, 0);
    do {
        ll x = findSwaps(n, arr);
        res[x]++;
        total += x;
    } while (next_permutation(arr.begin(), arr.end()));
    // cerr << "res = " << res << endl;
    FOR(i, 0, n*(n-1)/2 + 1) {
        cerr << i << " : " << res[i] << endl;
    }
    cerr << "total = " << total << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        ll n; cin >> n;
        ll x = (n*(n-1)) / 2;
        cout << "Case " << tc << ": ";
        // test(n);
        // cerr << x << endl;
        if (x % 2 == 0) {
            cout << x / 2 << endl;
        } else {
            cout << x << "/" << 2 << endl;
        }
        

    }
    return 0;
}