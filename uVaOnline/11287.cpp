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

vl primes;
int nMax = 1e6 + 1;
vi check(nMax, true);

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

ll pow(ll a, ll p, ll m) {
    if (p == 1) return a;
    ll r = pow(a, p/2, m);
    r = (r * r) % m;
    if (p % 2 != 0) {
        r = (r * a) % m;
    }
    return r;
}

bool isPrime(ll n) {
    for(int i = 0; primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            return false;
        }
    }
    return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    sieveOfPrimes();
    while (true) {
        ll p , a;
        cin >> p >> a;
        if (p == 0 && a == 0) break;
        bool check = false;
        if (!isPrime(p)) {
            if (pow(a, p, p) == a) {
                check = true;
            }
        }
        cout << (check?"yes":"no") << endl;
    }
    return 0;
}