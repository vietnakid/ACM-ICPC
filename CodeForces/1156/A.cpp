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

const int CIRCLE = 1;
const int TRIANGLE = 2;
const int SQUARE = 3;

int arr[105];

void vietnakid() {
    int n; cin >> n;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] == CIRCLE) {
            if (arr[i-1] == CIRCLE) {
                res += INF;
            } else if (arr[i-1] == TRIANGLE) {
                res += 3;
            } else if (arr[i-1] == SQUARE) {
                res += 4;
            }
        } else if (arr[i] == TRIANGLE) {
            if (arr[i-1] == CIRCLE) {
                if (i >= 2 && arr[i-2] == SQUARE) {
                    res += 2;
                } else 
                    res += 3;
            } else if (arr[i-1] == TRIANGLE) {
                res += INF;
            } else if (arr[i-1] == SQUARE) {
                res += INF;
            }
        } else if (arr[i] == SQUARE) {
            if (arr[i-1] == CIRCLE) {
                res += 4;
            } else if (arr[i-1] == TRIANGLE) {
                res += INF;
            } else if (arr[i-1] == SQUARE) {
                res += INF;
            }
        }
    }
    if (res >= INF) {
        cout << "Infinite\n";
    } else {
        cout << "Finite\n";
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