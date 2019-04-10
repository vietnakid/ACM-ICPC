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
int t[100005], f[100005];
vi a(100005);

void vietnakid() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < m; i++) cin >> f[i];
    for (int i = 0; i < m; i++) {
        vi b(100005);
        int curTime = 0;
        for (int j = 0; j < n; j++) {
            b[j] = max(max(a[j], curTime) + t[j] * f[i], a[j+1]);
            curTime = b[j];
            cerr << "car: " << i << " | nguoi: " << j << " " << b[j] << "\n";
        }
        a = b;
    }
    cout << a[m-1]+1 << "\n";
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