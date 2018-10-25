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

const int nMax = 1e6+1;

vi numOfPrimes(nMax, 0);
bitset<1000001> isUnique;

void init() {
    isUnique.set();
    numOfPrimes[1] = 1;
    
    FOR(i, 2, nMax) {
        if (numOfPrimes[i] == 0) {
            for(int j = i; j < nMax; j += i) {
                numOfPrimes[j]++;
                if (j >= (i*i) && j % (i*i) == 0) {
                    isUnique.reset(j);
                }
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
    init();
    vi mu(nMax, 0), M(nMax, 0);
    mu[1] = 1; M[1] = 1;
    FOR(i, 2, nMax) {
        if (isUnique[i]) {
            mu[i] = (numOfPrimes[i] % 2 == 0) ? 1 : -1;
        }
        M[i] = mu[i] + M[i-1];
    }
    int n;
    while (cin >> n) {
        if (n == 0) break;
        printf("%8d%8d%8d\n", n, mu[n], M[n]);
    }
    return 0;
}