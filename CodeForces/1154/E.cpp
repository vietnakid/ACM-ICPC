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

int n, k;
int arr[200005], pos[200005], res[200005], pre[200005], nex[200005];

void del(int u) {
    nex[pre[u]] = nex[u];
    pre[nex[u]] = pre[u];
}

void vietnakid() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        arr[i]= x;
        pos[x] = i;
        pre[i] = i-1;
        nex[i] = i+1;
    }
    int curTeam = 1;
    for (int i = n; i >= 1; i--) {
        int p = pos[i];
        if (res[p] == 0) {
            // cerr << i << " " << p << " team " << curTeam << "\n";
            res[p] = curTeam;
            for (int h = 1; h <= k; h++) {
                int _p = nex[p];
                if (_p > n) break;
                res[_p] = curTeam;
                del(_p);
            }
            for (int h = 1; h <= k; h++) {
                int _p = pre[p];
                if (_p < 1) break;
                res[_p] = curTeam;
                del(_p);
            }
            del(p);
            if (curTeam == 1) curTeam = 2;
            else curTeam = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i];
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