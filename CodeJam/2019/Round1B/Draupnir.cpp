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

void solveType1() {
    int64_t arr[6][7];
    int64_t coeffient[6];

    for (int i = 0; i < 6; i++) {
        cout << i+1 << "\n";
        cout.flush();
        cin >> arr[i][6];
        if (arr[i][6] == -1) {
            exit(0);
        }
    } 
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            int ii = i+1, jj = j+1;
            arr[i][j] = (1 << (ii/jj));
        }
    }

    for (int i = 0; i < 6; i++) {
        if (!arr[i][i]) {
            for (int j = i+1; j < 6; j++) {
                if (arr[j][i]) {
                    for (int k = 0; k <= 6; k++) {
                        swap(arr[i][k], arr[j][k]);
                    }
                }
            }
        }

        ll inv = powMod(arr[i][i], nMod -2);
        for (int j = i; j <= 6; j++) {
            arr[i][j] = mulmod(arr[i][j], inv);
        }

        for (int j = i+1; j < 6; j++) {
            ll t = arr[j][i];
            for (int k = 0; k <= 6; k++) {
                arr[j][k] = ((arr[j][k] - mulmod(arr[i][k], t)) % nMod + nMod) % nMod;
            }
        }
    }

    // for (int i = 0; i < 6; i++) {
    //     for (int j = 0 ; j <= 6; j++) {
    //         cerr << arr[i][j] << " ";
    //     }
    //     cerr << "\n";
    // }
    // cerr << "\n";

    for (int i = 5; i >= 0; i--){
        ll s = arr[i][6];
        for (int j = 5; j > i; j--) {
            s = ((s - arr[i][j]*coeffient[j]) % nMod + nMod) % nMod;
        }
        coeffient[i] = s;
    }
    for (int i = 0; i < 6; i++) {
        cout << coeffient[i] << " ";
    }
    cout << "\n";
    cout.flush();
    int res; cin >> res;
    if (res == -1) exit(0);
}

void solveType2() {
    int64_t arr[2][3] = {{2, 1}, {2, 2}};
    int64_t brr[2][6] = {{32, 4, 2, 2, 2, 1}, {64, 8, 4, 2, 2, 2}};
    int64_t coeffient[6];
    int64_t x[2];

    for (int i = 0; i < 2; i++) {
        cout << i+5 << "\n";
        cout.flush();
        cin >> x[i];
    } 

    for (coeffient[0] = 0; coeffient[0] <= 100; coeffient[0]++) {
     for (coeffient[1] = 0; coeffient[1] <= 100; coeffient[1]++)
      for (coeffient[2] = 0; coeffient[2] <= 100; coeffient[2]++)
       for (coeffient[3] = 0; coeffient[3] <= 100; coeffient[3]++) {
            // for (int i = 0; i < 2; i++) {
            //     ll cnt = x[i];
            //     for (int j = 0; j <= 3; j++) {
            //         cnt -= coeffient[j] * brr[i][j];
            //     }
            //     arr[i][2] = cnt;
            // }
            
            // ll s[2] = {0, 0};
            // for (int i = 0; i < 2; i++) {
            //     for (int j = 0; j < 6; j++) {
            //         s[i] += (coeffient[j]*brr[i][j]);
            //     }
            // }
            // if (s[0] == x[0] && s[1] == s[1]) {
            //     for (int i = 0; i < 6; i++) {
            //         cout << coeffient[i] << " ";
            //     }
            //     cout << "\n";
            //     return;
            // }
            
        }
    }
}

void vietnakid() {
    int TC, w; 
    cin >> TC >> w;
    for (int tc = 1; tc <= TC; tc++) {
        if (w == 6) {
            solveType1();
        } else {
            solveType2();
        }
    }
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