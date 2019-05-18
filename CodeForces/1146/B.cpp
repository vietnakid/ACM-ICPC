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

int arr[256], brr[256];

string cal(string a) {
    string res = "";
    for (auto c : a) {
        if (c != 'a') {
            res.push_back(c);
        }
    }
    cerr << a << " " << res << "\n";
    return res;
}

void vietnakid() {
	string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        arr[s[i]]++;
    }
    for (int i = n-1; i >= 0; i--) {
        int check = true;
        for (int j = 'b'; j <= 'z'; j++) {
            if (arr[j] != brr[j]) {
                check = false;
                break;
            }
        }
        if (check) {
            string t = s.substr(0, i+1) + cal(s.substr(0, i+1));
            cerr << s << " " << t << "\n";
            if (s == t) {
                cout << s.substr(0, i+1) << "\n";
            } else {
                cout << ":(" << "\n";
            }
            return;
        }
        brr[s[i]]++;
        arr[s[i]]--;
    }
    cout << ":(" << "\n";
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