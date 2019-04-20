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
vector<pair<int, pair<string, int> > > arr;
vi res(205);

void solve(string s) {
    string pre = "";
    string suf = "";
    int cnt = 0;
    for (int i = 0; i < 2*n-2; i+=2) {
        pre.push_back(s[cnt]);
        suf = s[n-cnt-1] + suf;
        cerr << pre << " " << suf << "\n";
        if (arr[i].second.first == pre && arr[i+1].second.first == suf) {
            res[arr[i].second.second] = 0;
            res[arr[i+1].second.second] = 1;
        } else if (arr[i+1].second.first == pre && arr[i].second.first == suf) {
            res[arr[i].second.second] = 1;
            res[arr[i+1].second.second] = 0;
        } else {
            return;
        }
        cnt++;
    }
    for (int i = 0; i < 2*n-2; i++) {
        if (res[i] == 0) {
            cout << "P";
        } else {
            cout << "S";
        }
    }
    cout << "\n";
    exit(0);
}

void vietnakid() {
	cin >> n;
    for (int i = 0; i < 2*n-2; i++) {
        string s;
        cin >> s;
        arr.push_back({s.size(), {s, i}});
    }
    sort(arr.begin(), arr.end());
    string s1 = arr[2*n-4].second.first;
    string s2 = arr[2*n-3].second.first;
    string s;
    if (s1.substr(1, n-2) == s2.substr(0, n-2)) {
        s = s1[0] + s1.substr(1, n-2) + s2[n-2];
        solve(s);
    }
    if (s2.substr(1, n-2) == s1.substr(0, n-2)) {
        s = s2[0] + s2.substr(1, n-2) + s1[n-2];
        solve(s);
    }
    cerr << s1 << " " << s2 << "\n";
    cerr << s1.substr(1, n-2) << " " << s2.substr(0, n-2) << "\n";
    cerr << s << "\n";
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