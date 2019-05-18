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

int cnt[256];

bool check(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (abs(s[i] - s[i-1]) == 1)    
            return false;    
    }
    return true;
}

void vietnakid() {
    int TC; cin >> TC;
    while (TC--) {
        string s; cin >> s;
        memset(cnt, 0, sizeof(cnt));
        for (auto x : s) {
            cnt[x]++;
        }
        string resEven = "";
        for (int i = 'a'; i <= 'z'; i+=2) {
            for (int j = 0; j < cnt[i]; j++) {
                resEven.push_back((char)i);
            }
        }
        string resOdd = "";
        for (int i = 'b'; i <= 'z'; i+=2) {
            for (int j = 0; j < cnt[i]; j++) {
                resOdd.push_back((char)i);
            }
        }
        if (check(resEven + resOdd)) {
            cout << resEven + resOdd << "\n";
        } else if (check(resOdd + resEven)) {
            cout << resOdd + resEven << "\n";
        } else {
            cout << "No answer\n";
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