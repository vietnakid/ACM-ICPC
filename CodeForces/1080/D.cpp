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

vector<uint64_t> f;
uint64_t pow4[32];

void init() {
    f.push_back(0);
    pow4[0] = 1;
    for (int i = 1; ;i++) {
        f.push_back(1 + 4*f[i-1]);
        // cerr << i << " " << f[i] << "\n";
        if (f.back() > 1e18) {
            break;
        }
        pow4[i] = 4 * pow4[i-1];
    }
    
}

void vietnakid() {
    init();
    int TC; cin >> TC;
    while (TC--) {
        uint64_t n, k;
        cin >> n >> k;
        if (n >= 32) {
            cout << "YES " << n-1 << "\n";
        } else if (f[n] < k) { 
            cout << "NO" << "\n";
        } else {
            uint64_t stepUsed = 0;
            uint64_t stepRemain = 0;
            int i = 0;
            for (; i < 31; i++) {
                ll edgeLeng = 1 << i;
                ll pathLeng = edgeLeng*2 - 1;
                ll remainStepI = (1 << (i+1))*2 - 3;
                stepRemain += remainStepI * f[n-i-1];
                stepUsed += pathLeng;
                // cerr << edgeLeng << " " << pathLeng << " " << remainStepI << "\n";
                // cerr << "stepUsed = " << stepUsed << " | stepRemain = " << stepRemain << "\n";
                if (stepUsed <= k && stepUsed + stepRemain >= k) {
                    cout << "YES " << n-i-1 << "\n";
                    break;
                }
                if (stepUsed > k) {
                    cout << "NO\n";
                    break;
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