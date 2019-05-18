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

int n, k;
int arr[35];

void vietnakid() {
    cin >> n >> k;
    if (k < __builtin_popcount(n) || k > n) {
        cout << "NO" << "\n";
    } else {
        int cnt = 0;
        for (int i = 0; i <= 31; i++) {
            if ((n >> i) & 1) {
                cerr << i << "\n";
                arr[i]++;
                cnt++;
            }
        }
        for (int i = 31; i > 0 && cnt < k; i--) {
            while (arr[i] > 0 && cnt < k) {
                arr[i]--;
                arr[i-1] += 2;
                cnt++;
            }
        }
        cout << "YES\n";
        for (int i = 31; i >= 0; i--) {
            for (int j = 0; j < arr[i]; j++) {
                cout << (1 << i) << " ";
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