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


vi primes;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    sieveOfPrimes();
    while (true) {
        int n, m, cnt = 0;
        cin >> n;
        m = n;
        if (n == 0) break;
        cout << m << " = ";
        if (n < 0) {
            cout << -1;
            n = -n;
            cnt++;
        }
        for (int i = 0; i < primes.size() &&  primes[i] * primes[i] <= n; i++) {
            while (n % primes[i] == 0) {
                if (cnt > 0) {
                    cout << " x ";
                }
                cout << primes[i];
                n /= primes[i];
                cnt++;
            }
        }
        if (n > 1) {
            if (cnt > 0) {
                cout << " x ";
            }
            cout << n;
        }
        cout << endl;
    }
    return 0;
}