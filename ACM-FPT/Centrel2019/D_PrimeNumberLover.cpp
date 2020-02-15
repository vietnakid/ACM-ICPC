#include <bits/stdc++.h>
#include <unistd.h>

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

unordered_set<int> primes;
int nMax = 1e6 + 1;
bitset<10000001> check;
int b = 100000;
int BIT[2*100000+2];

void setBIT(int x, int val) {
    while (x < 2*b) {
        BIT[x] += val;
        x += x & (-x);
    }
}

int getBIT(int x) {
    int res = 0;
    while (x > 0) {
        res += BIT[x];
        x -= x & (-x);
    }
    return res;
}

void sieveOfPrimes() {
    check.set();
    check[0] = false;
    check[1] = false;
    for (int i = 2; i < nMax; i++) {
        if (check[i]) {
            primes.insert(i);
            ll j = (ll)i * (ll)i;
            while (j <= nMax) {
                check[j] = false;
                j += i;
            }
        }
    }
}

void vietnakid() {
    sieveOfPrimes();
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (primes.find(x) == primes.end()) {
            arr[i] = -1;
        } else {
            arr[i] = 1;
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
        setBIT(s + b, 1);
        // cerr << s << "\n";
    }

    ll res = 0;
    s = 0;
    for (int i = 0; i < n; i++) {
        int cnt = (n - i) - getBIT(s-1 + b);
        // cerr << s << " " << cnt << "\n";
        res += cnt;
        s += arr[i];
        setBIT(s + b, -1);
    }

    cout << res << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	// cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}