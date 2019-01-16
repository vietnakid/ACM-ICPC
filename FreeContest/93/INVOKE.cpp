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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

vi primes;
int nMax = 1e7 + 1;
bitset<100000001> check;
int digits[10][10][10][10][10][10][10];
vvi digitsPrimes;

vi calDigits(int x) {
    vi cnt(10, 0);
    while (x > 0) {
        int m = x % 10;
        cnt[m]++;
        x /= 10;
    }
    return cnt;
}

void sieveOfPrimes() {
    check[0] = false;
    check[1] = false;
    FOR(i, 2, nMax) {
        if (check[i]) {
            digitsPrimes.push_back(calDigits(i));
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
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    check.set();
    sieveOfPrimes();
    memset(digits, 0, sizeof(digits));
    int TC;
    cin >> TC;
    while (TC--) {
        string n;
        cin >> n;
        vi cur(10, 0);
        for(int i = 0; i < n.size(); i++) {
            cur[n[i] - '0']++;
        }
        int res = 0;
        for (auto & x : digitsPrimes) {
            bool check = true;
            for (int i = 0; i < 10; i++) {
                if (x[i] > cur[i]) {
                    check = false;
                    break;
                }
            }
            res += check;
        }
        cout << res << endl;
    }
    return 0;
}