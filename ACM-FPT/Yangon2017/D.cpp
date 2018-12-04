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
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

vi primes, composite;
int nMax = 1e6 + 1;
bitset<10000001> check;

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
        } else {
            composite.push_back(i);
        }
    }
}

int n = 0, m = 0;

void sovle(char c) {
    int arr[8];
    for(int i = 0; i < 8; i++) {
        arr[7-i] = (c >> i) & 1;
    }
    
    // cerr << c << endl;
    for(int i = 0; i < 8; i++) {
        // cerr << arr[i];
        if (i != 0) {
            cout << ",";
        }
        if (arr[i] == 1) {
            cout << primes[n++];
        } else {
            cout << composite[m++];
        }
    }
    // cerr << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    check.set();
    sieveOfPrimes();
    int TC; cin >> TC;
    string a;
    getline(cin, a);
    while (TC--) {
        getline(cin, a);
        n = 0;
        m = 0;
        for (int i = 0; i < a.size(); i++) {
            if (i != 0) {
                cout << ",";
            }
            sovle(a[i]);
        }
        cout << endl;
    }
    return 0;
}