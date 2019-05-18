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
int cnt[3];
string s;

void vietnakid() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cnt[s[i]-'0']++;
    }
    for (int i = 0; i < 3; i++) {
        cnt[i] -= n/3;
        // cerr << cnt[i] << "\n";
    }
    for (int i = 0; i < n; i++) {
        if (cnt[s[i] - '0'] > 0) {
            for (int j = 0; j < 3; j++) {
                if (cnt[j] < 0 && j < s[i]-'0') {
                    cnt[s[i] - '0']--;
                    cnt[j]++;
                    s[i] = j + '0';
                    break;
                }
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (cnt[s[i] - '0'] > 0) {
            for (int j = 2; j >= 0; j--) {
                if (cnt[j] < 0 && j > s[i]-'0') {
                    cnt[s[i] - '0']--;
                    cnt[j]++;
                    s[i] = j + '0';
                    break;
                }
            }
        }
    }
    cout << s << "\n";
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