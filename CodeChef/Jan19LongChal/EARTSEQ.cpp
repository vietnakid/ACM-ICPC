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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
vl primes;
int nMax = 1e6 + 1;
bitset<1000001> check;

void sieveOfPrimes() {
    check.set();
    check[0] = false;
    check[1] = false;
    for (int i = 2; i < nMax; i++) {
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

ll res[50000];

void solve() {
    res[0] = 6;
    res[1] = 10;
    res[2] = 15;
    for (int i = 3; i < n; i++) {
        res[i] = res[i % 3] * primes[i+5];
    }
    if (n%3 != 0) {
        res[0] *= 7;
        res[n-1] *= 7;
        res[n-1] *= 11;
        res[n-2] *= 11;
        if (n%3 == 1) {
            res[n-1] /= 6;
        }
        if (n%3 == 2) {
            res[n-1] /= 10;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    sieveOfPrimes();
    int TC; cin >> TC;
    while (TC--) {
        cin >> n;
        solve();
    }
    return 0;
}