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

ll nMod = 1e6 + 3;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

vvl arr(12, vl(12));
vl coeffient(11);

ll powMod(ll a, ll n, ll mod = nMod) {
	if (n == 0 && a != 0) return 1;
    if (n == 0 && a == 0) return 0;
	if (n == 1) return a;
	ll b = powMod(a, n >> 1, mod);
	ll res = (b * b) % mod;
	if (n & 1) res = (res * a) % mod;
	return res;
}

ll divmod(ll a, ll b, ll mod = nMod) { // a div b = a * b^(p-2)
	b = powMod(b, mod - 2, mod);
	return (a * b) % mod;
} 

ll mulmod(ll a, ll n, ll mod = nMod) {
    if (n == 0) return 0;
	if (n == 1) return a;
	ll b = mulmod(a, n >> 1, mod);
	ll res = (b + b) % mod;
	if (n & 1) res = (res + a) % mod;
	return res;
}

ll query(ll x) {
    cout << "? " << x << "\n";
    cout.flush();
    int res; 
    cin >> res;

    // ll co[] = {1, 0, 99999, 0, 0, 23, 11, 50, 123, 0, 0};
    // res = 0;
    // ll p = 1;
    // for (int i = 0; i <= 10; i++) {
    //     res = (res + co[i] * p) % nMod;
    //     p = (p * x) % nMod;
    // }

    cerr << "answer = " << res << '\n';
    return res;
}



void init() {
    arr[0][0] = 1;
    arr[0][11] = query(0);
    coeffient[0] = arr[0][11];

    for (int i = 1; i <= 10; i++) {
        ll t = 1;
        for (int j = 0; j <= 10; j++) {
            arr[i][j] = t;
            t = (t * i) % nMod;
        }
        arr[i][11] = query(i);
    }

    for (int i = 0; i <= 10; i++) {
        if (!arr[i][i]) {
            for (int j = i+1; j <= 10; j++) {
                if (arr[j][i]) {
                    for (int k = 0; k <= 11; k++) {
                        swap(arr[i][k], arr[j][k]);
                    }
                }
            }
        }

        ll inv = powMod(arr[i][i], nMod -2);
        for (int j = i; j <= 11; j++) {
            arr[i][j] = mulmod(arr[i][j], inv);
        }

        for (int j = i+1; j <= 10; j++) {
            ll t = arr[j][i];
            for (int k = 0; k <= 11; k++) {
                arr[j][k] = ((arr[j][k] - mulmod(arr[i][k], t)) % nMod + nMod) % nMod;
            }
        }

        // for (int ii = 0; ii <= 10; ii++) {
        //     for (int j = 0 ; j <= 11; j++) {
        //         cerr << arr[ii][j] << " ";
        //     }
        //     cerr << "\n";
        // }
        // cerr << "\n";

    }
}

void gausse() {
    for (int i = 11; i >= 1; i--){
        ll s = arr[i][11];
        for (int j = 10; j > i; j--) {
            s = ((s - arr[i][j]*coeffient[j]) % nMod + nMod) % nMod;
        }
        coeffient[i] = s;
    }
    for (int i = 0; i <= 10; i++) {
        cerr << coeffient[i] << " ";
    }
    cerr << "\n";
    for (int i = 0; i < nMod; i++) {
        ll res = 0;
        ll p = 1;
        for (int j = 0; j <= 10; j++) {
            res = (res + p*coeffient[j]) % nMod;
            p = (p * i) % nMod;
        }
        if (res == 0) {
            cout << "! " << i << "\n";
            return;
        }
    }
    cout << "! -1" << "\n";
}


void vietnakid() {
	init();
    gausse();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}