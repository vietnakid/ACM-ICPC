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

int n, m, h;
int arr[105], brr[105];
int hrr[105][105], res[105][105];

void vietnakid() {
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> brr[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> hrr[i][j];
            if (hrr[i][j] == 1) {
                res[i][j] = min(brr[i], arr[j]);
            } else {
                res[i][j] = 0;
            }
            cout << res[i][j] << " ";
        }
        cout << "\n";
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