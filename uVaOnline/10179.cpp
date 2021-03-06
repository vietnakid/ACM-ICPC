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
int nMax = 31623;
bitset<31623> check;
int pSize = 0;

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

vi cal(int n) {
    vi res;
    for(int i = 0; i < pSize && primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            res.push_back(primes[i]);
        }
        while (n % primes[i] == 0) {
            n /= primes[i];
        }
    }
    if (n > 1) {
        res.push_back(n);
    }
    return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    check.set();
    sieveOfPrimes();
    pSize = primes.size();
    int n = 0;
    while (cin >> n) {
        if (n == 0) break;
        vi pri = cal(n);
        int sizePri = pri.size();
        int res = 0;
        FOR(i, 1, 1 << sizePri) {
            int cnt = 0;
            int mul = 1;
            FOR(j, 0, sizePri) {
                int x = (i >> j) & 1;
                if (x == 1) {
                    cnt++;
                    mul *= pri[j];
                }
            }
            if (cnt % 2 == 0) {
                res -= n / mul;
            } else {
                res += n / mul;
            }
        }
        cout << n - res << endl;
    }
    return 0;
}