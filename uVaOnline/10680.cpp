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

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

vi primes;
int nMax = 1e6 + 1;
bitset<10000001> check;

void sieveOfPrimes() {
    check[0] = false;
    check[1] = false;
    FOR(i, 2, nMax) {
        if (check[i]) {
            primes.push_back(i);
            ll j = (ll)i * (ll)i;
            while (j <= nMax) {
                check[j] = false;
                j += i;
            }
        }
    }
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    check.set();
    sieveOfPrimes();
    while (true) {
        int n;
        cin >> n;
        ll res = 1;
        if (n == 0) break;
        primes[2] = 3;
        for(int i = 2; i < primes.size() && primes[i] <= n; i++) {
            ll p = primes[i];
            ll x = 1;
            while (x * p <= n) {
                x *= p;
                res = (res * p) % 10;
                // cerr << p << " " << res << endl;
            }
        }
        int k = int(log(n)/log(2)) - int(log(n)/log(5));
        // cerr << k << endl;
        FOR(i, 0, k) {
            res = (res * 2) % 10;
        }
        
        cout << res << endl;
        // cerr << endl;
    }
    return 0;
}