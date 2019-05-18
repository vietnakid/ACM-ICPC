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

vi pos;

char deterChar(int plus, int total) {
    vi cnt(5, 0);
    vvi p(5);
    // cerr << plus <<  " step contains: " << pos.size() << " steps\n";
    for (int i = 0; i < pos.size(); i++) {
        int num = pos[i]*5 + plus;
        cout << num << "\n";
        cout.flush();
        char x; cin >> x;
        // cerr << num << " " << x << "\n";
        cnt[x - 'A']++;
        p[x - 'A'].push_back(num/5);
    }
    // for (int i = 0; i < 5; i++) {
    //     cerr << cnt[i] << " ";
    // }
    // cerr << "\n";
    for (int i = 0; i < 5; i++) {
        if (cnt[i] == total) {
            pos = p[i];
            return i + 'A';
        }
    }
}

void solveSingleCase() {
    pos.clear(); pos.resize(0);
    for (int i = 0; i < 119; i++)
        pos.push_back(i);
    string res = "";
    res += deterChar(1, 23);
    // cerr << "res = " <<  res << "\n";
    res += deterChar(2, 5);
    // cerr << "res = " <<  res << "\n";
    res += deterChar(3, 1);
    // cerr << "res = " <<  res << "\n";
    string _res = res + deterChar(4, 1);
    for (int i = 'A' ; i <= 'E'; i++) {
        bool check = true;
        for (int j = 0; j < 4; j++) 
            if (i == _res[j]) check = false;
        if (check) res += i;
    }
    // cerr << "res = " <<  res << "\n";

    for (int i = 'A' ; i <= 'E'; i++) {
        bool check = true;
        for (int j = 0; j < 4; j++)
            if (i == res[j]) 
                check = false;
        if (check) res += i;
    }
    // cerr << "res = " <<  res << "\n";
    cout << res << "\n";
    cout.flush();
    string o; cin >> o;
    if (o == "N") exit(0);
}

void vietnakid() {
    int TC, t; cin >> TC >> t;
    while (TC--) {
        solveSingleCase();
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}