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
int cnt8, cnt0;

void vietnakid() {
    cin >> n;
    cin >> s;
    int i = 0, j = 0, turn = 0;
    while (n - cnt8 - cnt0 != 11) {
        if (turn == 0) {
            while (i < n && s[i] == '8') {
                i++;
            } 
            cnt8++;
            if (i < n) i++;
        } else {
            while (j < n && s[j] != '8') j++;
            cnt0++;
            if (j < n) j++;
        }
        turn = 1 - turn;
    }
    while (i < n && s[i] == '8') {
        i++;
    } 
    while (j < n && s[j] != '8') {
        j++;
    } 
    cerr << i << " " << j << "\n";
    if (i > j) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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