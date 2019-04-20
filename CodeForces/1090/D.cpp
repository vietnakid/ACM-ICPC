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
vvi arr(100005);

void vietnakid() {
	cin >> n >> m;
    if (n == 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }   
    ii res = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (arr[i].size() < n-1) {
            set<int> st;
            for (auto x : arr[i]) 
                st.insert(x);
            for (int j = 1; j <= n; j++) {
                if (i != j && st.find(j) == st.end()) {
                    res = {i, j};
                    break;
                }
            }
            break;
        }
    }
    if (res.first == 0) {
        cout << "NO" << "\n";
    } else {
        cout << "YES\n";
        cerr << res.first << " " << res.second << "\n";
        int cnt = 3;
        for (int i = 1; i <= n; i++) {
            if (i == res.first) {
                cout << 1 << " ";
            }
            else if (i == res.second) {
                cout << 2 << " ";
            } else {
                cout << cnt << " ";
                cnt++;
            }
        }
        cout << "\n";
        cnt = 2;
        for (int i = 1; i <= n; i++) {
            if (i == res.first) {
                cout << 1 << " ";
            }
            else if (i == res.second) {
                cout << 1 << " ";
            } else {
                cout << cnt << " ";
                cnt++;
            }
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