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

int n;
uint64_t arr[100005], s[100005];

void vietnakid() {
	cin >> n;
    for (int i = 2; i <= n; i += 2) cin >> arr[i];
    uint64_t a = 1;
    for (int i = 2; i <= n; i += 2) {
        while (true) {
            uint64_t b = a*a + arr[i];
            uint64_t t = sqrt(b);
            if (t == a) {
                cout << "No\n";
                exit(0);
            }
            if (t*t == b) {
                arr[i-1] = a*a - s[i-2];
                s[i-1] = s[i-2] + arr[i-1];
                s[i] = s[i-1] + arr[i];
                a = t + 1;
                break;
            }
            // cerr << i << " " << a << "\n";
            a++;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
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