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

int arr[] = {4, 8, 15, 16, 23,  42};
int brr[4];

void vietnakid() {
    for (int i = 1; i <= 4; i++) {
        cout << "? " << 1 << " " << i+1 << "\n";
        cin >> brr[i-1];
        cout.flush();
    }
    do {
        bool check = true;
        for (int i = 1; i <= 4; i++) {
            if (arr[0] * arr[i] != brr[i-1]) {
                check = false;
                break;
            }
        }
        if (check) {
            cout << "! ";
            for (int i = 0; i < 6; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    } while (next_permutation(arr, arr+6));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}