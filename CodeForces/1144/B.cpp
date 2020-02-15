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
	int n;
    cin >> n;
    vi even, odd;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2 == 0) {
            even.push_back(x);
        } else {
            odd.push_back(x);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    if (even.size() > odd.size()) {
        int sum = 0;
        for (int i = 0; i < even.size() - odd.size() - 1; i++) {
            sum += even[i];
        }
        cout << sum << "\n";
    } else if (odd.size() > even.size()) {
        int sum = 0;
        for (int i = 0; i < odd.size() - even.size() - 1; i++) {
            sum += odd[i];
        }
        cout << sum << "\n";
    } else {
        cout << 0 << "\n";
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