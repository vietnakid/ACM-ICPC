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

void vietnakid() {
    int res = 1;
    while (true) {
        res++;
        int cnt = 0, odd = 0;
        for (int i = 1; i*i <= res; i++) {
            if (i*i == res) {
                cnt += 1;
                if (i % 2 == 1) {
                    odd++;
                }
            } else {
                if (res % i == 0) {
                    cnt += 2;
                    int j = res / i;
                    if (i % 2 == 1) {
                        odd++;
                    }
                    if (j % 2 == 1) {
                        odd++;
                    }
                    cerr << res << " " << i << " " << j << "\n";
                }
            }
        }
        cerr << res << " " << cnt << " " << odd << "\n";
        if (cnt == 20 && odd == 4) {
            cout << res << "\n";
            break;
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