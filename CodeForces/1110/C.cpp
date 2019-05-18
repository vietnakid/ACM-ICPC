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

map<int, int> specialCase;

void init() {
    vii preCal{ {1,0}, {3,1}, {7,1}, {15,5}, {31,1}, {63,21}, {127,1}, {255,85}, {511,73}, {1023,341}, {2047,89}, {4095,1365}, {8191,1}, {16383,5461}, {32767,4681}, {65535,21845}, {131071,1}, {262143,87381}, {524287,1}, {1048575,349525}, {2097151,299593}, {4194303,1398101}, {8388607,178481}, {16777215,5592405}, {33554431,1082401}, {67108863,22369621}, {134217727,19173961} };
    for (auto x : preCal) {
        specialCase[x.first] = x.second;
    }
}

void vietnakid() {
    init();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (specialCase.count(x)) {
            cout << specialCase[x] << "\n";
        } else {
            int i = 0;
            for (; i < 30 && (1 << i) <= x; i++);
            int b = (1 << i) - 1;
            cout << b << "\n";
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