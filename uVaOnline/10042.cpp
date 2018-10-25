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
// int nMax = 1e6 + 1;
int nMax = 31624;
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

int sumNum(int n) {
    int sumNum = 0;
    while (n > 0) {
        sumNum += n % 10;
        n /= 10;
    }
    return sumNum;
}

bool testNum(int n) {
    int N = n;
    int sumN = sumNum(n);
    int sumP = 0;
    FOR(i, 0, primes.size()) {
        int p = primes[i];
        if (p * p > N) {
            break;
        }
        while (n % p == 0) {
            n /= p;
            sumP += sumNum(p);
        }
    }
    if (n > 1 && sumP > 0) {
        sumP += sumNum(n);
    }
    return sumN == sumP;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    sieveOfPrimes();
    int TC; cin >> TC;
    FOR(tc, 0, TC) {
        int n; cin >> n;
        while (true) {
            n++;
            if (testNum(n)) {
                cout << n << endl;
                break;
            }
        }
    }
    return 0;
}