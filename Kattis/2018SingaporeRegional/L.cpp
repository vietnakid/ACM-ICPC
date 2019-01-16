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

vi primes;
int nMax = 2e6 + 1;
bitset<20000001> check;
int numFactor[20000001], numPrimeFactor[20000001];


void sieveOfPrimes() {
    check.set();
    for(int i = 0; i < 20000001; i++) {
        numFactor[i] = 1;
    }
    memset(numPrimeFactor, 0, sizeof(numPrimeFactor));
    check[0] = false;
    check[1] = false;
    for (int i = 2; i < nMax; i++) {
        if (check[i]) {
            primes.push_back(i);
            ll j = (ll)i + (ll)i;
            while (j <= nMax) {
                check[j] = false;
                numPrimeFactor[j]++;
                ll k = j;
                int s = 1;
                while (k % i == 0) {
                    s++;
                    k /= i;
                }
                numFactor[j] *= s;
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
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    sieveOfPrimes();
    // cerr << numFactor[100] << " " << numPrimeFactor[100] << endl;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", numFactor[x] - numPrimeFactor[x]);
    }
    return 0;
}