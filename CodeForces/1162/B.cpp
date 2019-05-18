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

int n, m;
int arr[55][55], brr[55][55];

void vietnakid() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> brr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > brr[i][j]) {
                swap(arr[i][j], brr[i][j]);
            }
        }
    }
    bool check = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cerr << brr[i][j] << " ";
            if (i > 0 && arr[i][j] <= arr[i-1][j]) {
                check = false;
            }
            if (j > 0 && arr[i][j] <= arr[i][j-1]) {
                check = false;
            }
            if (i > 0 && brr[i][j] <= brr[i-1][j]) {
                check = false;
            }
            if (j > 0 && brr[i][j] <= brr[i][j-1]) {
                check = false;
            }
        }
        cerr << "\n";
    }
    if (check) {
        cout << "Possible\n";
    } else {
        cout << "Impossible\n";
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