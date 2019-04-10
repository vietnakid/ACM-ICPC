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
	int x, y, z;
    cin >> x >> y >> z;
    if (z == 0) {
        if (y < x) {
            cout << y * 3 + z-y << "\n";
        } else {
            cout << x*3 << "\n";
        }
    } else {
        int res = 0;
        if (y < x) {
            if (z*2 <= y) 
                res = y * 3 + x-y;
            else
                res = y * 3 + x-y-1;
        } else {
            if (z*2 <= y) 
                res = x*3;
            else
                if (z*2-1 == y) 
                    res = (x-1)*3 + 1;
                else
                    res = (x-1)*3;
        }
        
        // for (int nw = 0; nw <= x; nw++) {
        //     for (int nd = 0; nd <= x-nw; nd++) {
        //         int nl = x - nw - nd;
        //         if (nw > )
        //     }
        // }
        cout << res << "\n";
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