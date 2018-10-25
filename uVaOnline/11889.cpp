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
int nMax = 3163;
bitset<3163> check;

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
    cerr << primes.size() << endl;
    int TC;
    cin >> TC;
    int t = primes.size();
    while (TC--) {
        
        int n, m;
        cin >> n >> m;
        bool check = true;
        int res = 1;
        for(int i = 0; i < t && (primes[i] * primes[i] <= n || primes[i] * primes[i] <= m); i++) {
            int a = 0, b = 0;
            while (n % primes[i] == 0) {
                 n /= primes[i];
                 a++;
            }
            while (m % primes[i] == 0) {
                 m /= primes[i];
                 b++;
            }
            if (a > b) {
                check = false;
                break;
            } else if (a < b) {
                FOR(j, 0, b) {
                    res *= primes[i];
                }
            }
        }
        if (m % n != 0) {
            check = false;
        } else {
            res *= m/n;
        }
        if (check) {
            cout << res << endl;
        } else {
            cout << "NO SOLUTION" << endl;
        }
    }
    return 0;
}