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
int arr[505][505];
int even[505][11], odd[505][11];

void vietnakid() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int b = 0; b < 10; b++) {
            if ((arr[1][i] >> b) & 1) {
                odd[1][b] = i;
            } else {
                even[1][b] = i;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int b = 0; b < 10; b++) {
                if ((arr[i][j] >> b) & 1) {
                    if (odd[i-1][b] != 0) {
                        even[i][b] = j;
                    }
                    if (even[i-1][b] != 0) {
                        odd[i][b] = j;
                    }
                } else {
                    if (odd[i-1][b] != 0) {
                        odd[i][b] = j;
                    }
                    if (even[i-1][b] != 0) {
                        even[i][b] = j;
                    }
                }
            }
        }
    }
    int check = -1;
    for (int b = 0; b < 10; b++) {
        if (odd[n][b] != 0) {
            check = b;
        }
    }
    if (check == -1) {
        cout << "NIE\n";
    } else {
        cout << "TAK\n";
        vi res;
        int state = 1;
        int j;
        // cerr << check << "\n";
        for (int i = n; i > 0; i--) {
            if (state == 1) {
                j = odd[i][check];
                res.push_back(j);
                // cerr << i << " " << j << " " << arr[i][j] << " " << ((arr[i][j] >> check) & 1) <<"\n";
                if ((arr[i][j] >> check) & 1) {
                    state = 2;
                }
            } else {
                j = even[i][check];
                res.push_back(j);
                if ((arr[i][j] >> check) & 1) {
                    state = 1;
                }
            }
                
        }

        reverse(res.begin(), res.end());
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
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