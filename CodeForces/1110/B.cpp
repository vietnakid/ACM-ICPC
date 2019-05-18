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

int n, m, k;
int brr[100005];
vii arr;
bitset<100005> connect;

void vietnakid() {
    cin >> n >> m >> k;
    for (int i = 0 ; i < n; i++) {
        cin >> brr[i];
    }
    for (int i = 0; i < n-1; i++) {
        arr.push_back({brr[i+1]-brr[i], i});
    }
    sort(arr.begin(), arr.end());
    connect.reset();
    for (int i = 0; i < n-k; i++) {
        connect[arr[i].second] = true;
    }
    int leng = k;
    for (int i = 0; i < n; i++) {
        if (connect[i]) {
            leng += brr[i+1]-brr[i];
        }
    }
    cout << leng << "\n";
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