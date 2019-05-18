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

int64_t a, b, m;
int64_t p2[55];

void vietnakid() {
    int TC; cin >> TC;
    p2[0] = 1;
    for (int i = 1; i < 55; i++) {
        p2[i] = 2 * p2[i-1];
    }

    while (TC--) {
        cin >> a >> b >> m;
        bool isOk = true;
        for (int i = 1; i < 50 && isOk; i++) {
            int64_t sum = 0, mmin = 0;
            int64_t s = p2[i] * a;
            if (s / p2[i] != a) {
                break;
            }
            sum += s;
            mmin = s;
            for (int j = i-1; j >= 0; j--) {
                int64_t s = p2[j] * m;
                if (s / p2[j] != m) {
                    break;
                }
                sum += s;
            }
            if (sum >= b) {
                cout << "OK\n";

                isOk = false;
                break;
            }
            if (isOk) {
                cout << -1 << "\n";
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