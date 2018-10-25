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


vl primes;
int nMax = 1e7 + 1;
// vi check(nMax, true);
bitset<100000001> check;

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
        ll n, cnt = 0;
        cin >> n;
        n = abs(n);
        if (n == 0) break;
        ll max = -1;
        for (int i = 0; i < primes.size() &&  primes[i] * primes[i] <= n; i++) {
            if (n % primes[i] == 0) { 
                cnt++;
                if (cnt > 1) {
                    max = primes[i];
                }
            }
            while (n % primes[i] == 0) {
                n /= primes[i];
            }
        }
        if (n > 1) {
            cnt++;
            if (cnt > 1) {
                max = n;
            }
        }
        cout << max << endl;
    }
    return 0;
}