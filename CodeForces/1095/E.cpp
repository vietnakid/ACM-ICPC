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
string s;
int sum[1000005], mmin[1000005];

void vietnakid() {
	cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + (s[i-1] == '(' ? 1 : -1);
    }
    mmin[n] = sum[n];
    for (int i = n-1; i >= 0; i--) {
        mmin[i] = min(mmin[i+1], sum[i]);
    }
    cerr << sum[n] << "\n";
    if (n % 2 == 1 || (sum[n] != 2 && sum[n] != -2)) {
        cout << "0\n";
    } else {
        if (sum[n] == -2) {
            if (mmin[0] == -2) {
                int cnt = 0;
                for (int i = 1; i <= n; i++) {
                    if (mmin[i] == -2 && sum[i] >= -1 && s[i-1] == ')') {
                        // cerr << i << " ";
                        cnt++;
                    }
                    if (sum[i] < 0) break;
                }
                cout << cnt << "\n";
            } else {
                cout << "0\n";
            }
        } else {
            if (mmin[0] < 0) {
                cout << "0\n";
            } else {
                int cnt = 0;
                for (int i = 1; i <= n; i++) {
                    if (mmin[i] >= 2 && sum[i] >= 2 && s[i-1] == '(') {
                        cerr << i << " ";
                        cnt++;
                    }
                }
                cout << cnt << "\n";
            }
        }
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