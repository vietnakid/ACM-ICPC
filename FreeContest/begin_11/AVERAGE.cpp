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

int n, a;

void vietnakid() {
    int TC; 
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &n, &a);
        ll res[40005];
        memset(res, 0, sizeof(res));
        res[20000] = 1;
        int _min = 20000;
        int _max = 20000;
        for (int i = 0 ; i < n; i++) {
            int x; 
            scanf("%d", &x);
            x -= a;
            if (x < 0) {
                for (int j = _min; j <= _max; j++) {
                    if (j + x >= 0 && j + x < 40005) {
                        res[j + x] = (res[j + x] + res[j]) % nMod;
                    }
                }
                _min = _min + x;
            } else {
                for (int j = _max; j >= _min; j--) {
                    if (j + x >= 0 && j + x < 40005) {
                        res[j + x] = (res[j + x] + res[j]) % nMod;
                    }
                }
                _max = _max + x;
            }

        }
        printf("%d\n", (res[20000] - 1) % nMod);
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
 	// cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}