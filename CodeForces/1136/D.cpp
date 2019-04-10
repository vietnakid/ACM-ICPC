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
vector<set<int> > back(300005), forw(300005);
vi arr(300005);
int res = 0;

bool canMove(int pos) {
    int dstPos = n-1-res;
    for (int i = pos+1; i <= dstPos; i++) {
        if (*back[arr[pos]].lower_bound(arr[i]) == arr[i]) {
            // swap(_arr[i], _arr[i+1]);
        } else {
            return false;
        }
    }
    for (int i = pos; i < dstPos; i++) {
        arr[pos] = arr[pos+1];
    }
    return true;
}

void vietnakid() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        forw[v].insert(u);
        back[u].insert(v);
    }
    for (int i = n-2; i >= 0; i--) {
        if (back[arr[i]].count(arr[n-1])) {
            int j = i;
            while (j < n-2 && back[arr[j]].count(arr[j+1])) {
                swap(arr[j], arr[j+1]);
                j++;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cerr << arr[i] << " ";
    // }
    int i = n-1;
    while (i > 0 && forw[arr[i]].count(arr[i-1])) {
        res++;
        swap(arr[i], arr[i-1]);
        i--;
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