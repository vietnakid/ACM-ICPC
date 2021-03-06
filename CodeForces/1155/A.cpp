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

vi f(256,INF), l(256, -1);

void vietnakid() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i <n; i++) {
        f[s[i]] = min(i+1, f[s[i]]);
        l[s[i]] = i+1;
    }
    // cerr << f['b'] << " " << l['a'] << "\n";
    for (int i = 'a'; i <= 'z'; i++) 
        for (int j = i+1; j <= 'z'; j++) {
            if (f[j] < l[i]) {
                cout << "YES\n";
                cout << f[j] << " " << l[i] << "\n";
                return;
            }
        }
    cout << "NO\n";
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