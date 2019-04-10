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
map<int, int> mp;
int cnt4 = 0;
int arr[25][25];

void exitNo() {
    cout << "No\n";
    exit(0);
}

void vietnakid() {
	cin >> n;
    for (int i = 0; i < n*n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    for (ii x : mp) {
        cnt4 += x.second / 4;
    }
    if (cnt4 < (n/2)*(n/2)) {
        cerr << cnt4 << "\n";
        exitNo();
    }
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            for (ii x : mp) {
                if (x.second >= 4) {
                    mp[x.first] -= 4;
                    int u = x.first;
                    arr[i][j] = u;
                    arr[i][n-j-1] = u;
                    arr[n-i-1][j] = u;
                    arr[n-i-1][n-j-1] = u;
                    break;
                }
            }
        }
    }
    if (n % 2 == 1) {
        for (int i = 0; i < n/2; i++) {
            for (ii x : mp) {
                if (x.second >= 2) {
                    mp[x.first] -= 2;
                    int u = x.first;
                    arr[i][n/2] = u;
                    arr[n-i-1][n/2] = u;
                    break;
                }
            } 
        }
        for (int i = 0; i < n/2; i++) {
            for (ii x : mp) {
                if (x.second >= 2) {
                    mp[x.first] -= 2;
                    int u = x.first;
                    arr[n/2][i] = u;
                    arr[n/2][n-i-1] = u;
                    break;
                }
            } 
        } 
        for (ii x : mp) {
            if (x.second >= 1) {
                mp[x.first] -= 1;
                arr[n/2][n/2] = x.first;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                exitNo();
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
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