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
vi arr[100005];
ll res = 0;

void vietnakid() {
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        int x; cin >> x;
        arr[x].push_back(i);
    }
    int pos[2] = {0, 0};
    for (int i = 1; i <= n; i++) {
        int dis = min(abs(pos[0] - arr[i][0]) + abs(pos[1] - arr[i][1]), abs(pos[0] - arr[i][1]) + abs(pos[1] - arr[i][0]));
        pos[0] = arr[i][0]; pos[1] = arr[i][1];
        res += dis;
    }
    cout << res << "\n";
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