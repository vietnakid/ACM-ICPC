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

void vietnakid() {
    int n; cin >> n;
    int N = n;
    vector<int> primes;
    for (int i = 2; i * i <= n; i++) {
        int x = 1;
        while (n % i == 0) {
            x *= i;
            n /= i;
        }
        if (x != 1) primes.push_back(x);
    }
    if (n != 1) {
        primes.push_back(n);
    }
    if (primes.size() == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int da = primes[0], ua, ub;
        int db = 1;
        for (int i = 1; i < primes.size(); i++) {
            db *= primes[i];
        }
        // cerr << da << " " << db << "\n";
        for (ua = 1; ua < da; ua++) {
            // cerr << (N - 1 - ua*db) << " " << da << "\n";
            if ((N - 1 - ua*db) % da == 0) {
                ub = (N - 1 - ua*db) / da;
                if (ub > 0 && ub < db) {
                    cout << "2\n";
                    cout << ua << " " << da << "\n";
                    cout << ub << " " << db << "\n";
                    return;
                }
            }
        }
    }
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
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}