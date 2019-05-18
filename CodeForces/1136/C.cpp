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
int arr[505][505], brr[505][505];
vector<multiset<int> > diaA(1005), diaB(1005);

void vietnakid() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> brr[i][j];
        }
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            diaA[i+j].insert(arr[i][j]);
            diaB[i+j].insert(brr[i][j]);
        }
    for (int i = 0; i < n+m; i++) {
        if (diaA[i] != diaB[i]) {
            cout << "NO\n";
            return; 
        }
    }
    cout << "YES\n";
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