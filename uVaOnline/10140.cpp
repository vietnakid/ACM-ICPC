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
    for (ll i = (a); i <= (b); i++)
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
int nMax = 65536 + 100;
vi check(nMax, true);
int n;

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

bool checkPrime(int a) {
    if (a < 2) {
        return false;
    }
    FOR(i, 0, n) {
        if (primes[i] * primes[i] > a) {
            return true;
        }
        if (a % primes[i] == 0) {
            return false;
        }
    }
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    sieveOfPrimes();
    n = primes.size();
    ll a, b;
    while (cin >> a >> b) {
        ii least = {0, INF}, most = {0, 0};
        int f = 0, l = 0;
        // cerr << a << " " << b << endl;
        FORE(i, a, b) {
            if (checkPrime(i)) {
                if (l == 0) {
                    l = i;
                } else {
                    f = l;
                    l = i;
                    if (l - f < least.second - least.first) {
                        least = {f, l};
                    }
                    if (l - f > most.second - most.first) {
                        most = {f, l};
                    }
                }
            }
        }
        if (least.first == 0) {
            printf("There are no adjacent primes.\n");
        } else {
            printf("%d,%d are closest, %d,%d are most distant.\n", least.first, least.second, most.first, most.second);
        }
    }
    return 0;
}